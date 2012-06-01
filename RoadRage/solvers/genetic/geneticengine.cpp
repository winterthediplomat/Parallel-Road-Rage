#include "geneticengine.h"
#include <math.h>
#include <cstdlib>
#include <ctime>

#include <omp.h>
//#include <algorithm>

GeneticEngine::GeneticEngine(unsigned int generations)
{
    this->generations=generations;
    this->elitistsNumber=0;
    this->crossover=0;
    this->gih=NULL;
}

void
GeneticEngine::setGIH(GraphInformationHandler *gih)
{
    this->gih=gih;
}

void
GeneticEngine::setPopulationDimension(unsigned int dimension)
{
    this->populationDimension=dimension;
}

unsigned int
GeneticEngine::getPopulationDimension()
{
    return this->populationDimension;
}

void
GeneticEngine::setMutationProbability(float mutProb)
{
    this->mutationProbability=mutProb;
}


float
GeneticEngine::getMutationProbability()
{
    return this->mutationProbability;
}
void
GeneticEngine::setCrossover(unsigned int crossover)
{
    //in order to avoid individual disappears passing
    //from a generation to another
    if(crossover&1)
        crossover++; //this behaviour should be selected by user
    this->crossover=crossover;
}
unsigned int
GeneticEngine::getCrossover()
{
    return  this->crossover;
}

void
GeneticEngine::setNewIndividualsNumber(unsigned int newIndividuals)
{
    this->newIndividualsNumber=newIndividuals;
}
unsigned int
GeneticEngine::getNewIndividualsNumber()
{
    return this->newIndividualsNumber;
}

void
GeneticEngine::setElitismNumber(unsigned int elitists)
{
    this->elitistsNumber=elitists;
}
unsigned int
GeneticEngine::getElitismNumber()
{
    return this->elitistsNumber;
}

Path
GeneticEngine::generateRandomPath(unsigned int solutionLength)
{
    Path newPath=this->gih->generateDefaultPath();
    for(unsigned int i=0; i<solutionLength; i++)
    {
        newPath.appendPoint(rand()%solutionLength);
    }
    return newPath;
}

void
GeneticEngine::initializePopulation(QVector<Path> *population,
                                    unsigned int championDim)
{
    //per adesso championDim:=1067, poi sarà trovato in maniera migliore.
    srand(time(NULL));
    unsigned int itemsNo=this->gih->getNodes().size();
    Path actualPath;
    for(unsigned int c=0; c<championDim; c++)
    {
        //actualPath=this->convertAddressToPath(rand()%pow(itemsNo, itemsNo), itemsNo);
        actualPath=this->generateRandomPath(itemsNo);
        population->append(actualPath);
    }
}

void
GeneticEngine::evaluatePopulation(QVector<Path>* population,
                                  QVector<unsigned int>* scoreOfPopulation,
                                  unsigned int howManyToEvaluate)
{
    cout<<"flushed all old data"<<endl;
    //re-evaluating only new solutions (childs and foreign)
    for(int i=0; i<howManyToEvaluate; i++)
        scoreOfPopulation->replace(i, 0);

    cout<<"starting evaluation of "<<(unsigned)population->size()<<endl;
    unsigned int individualScore=0;
    QVector<Constraint*> constraints=this->gih->getAcceptedConstraints();
    constraints+=this->gih->getRejectedConstraints();

#pragma omp for private(individualScore) nowait
    for(unsigned int popIndex=0; popIndex<howManyToEvaluate; popIndex++)
    {
        Path candidate=population->at(popIndex);
        individualScore=0;
        //unsigned int newValue;
        foreach(Constraint* constr, constraints)
        {

            individualScore+=constr->calculateSolutionScore(candidate);
        }

        scoreOfPopulation->replace(popIndex, individualScore);
    }
    cout<<"terminated score calculation"<<endl;
}

void
GeneticEngine::mutatePopulation(QVector<Path> *population)
{
    srand(3);
    for(unsigned int p_i=0; p_i<(population->size()-this->elitistsNumber); p_i++)
    {
        if((rand()/RAND_MAX)<this->mutationProbability)
        {
            //workaround. why have I decided to use objects instead of pointers?
            Path oldPath=population->at(p_i);
            Path newPath(oldPath.getNodes(), oldPath.getPath());
            for(int i=0; i<oldPath.getNodes(); i++)
                newPath.addName(oldPath.getNameByPoint(i));
            //one-point mutation
            newPath.replace(
                        rand()%newPath.getNodes(),
                        rand()%newPath.getNodes()
                        );
            //random mutation
            //for(int i=0; i<newPath.getNodes(); i++)
            //{
                //if(rand()/RAND_MAX<this->mutationProbability)
                //    newPath.replace(rand()%newPath.getNodes()
                //                    ,rand()%newPath.getNodes());
            //}
            population->replace(p_i, newPath);
        }
    }
    //cout;
}

void
GeneticEngine::sortPopulation(QVector<Path>* population, QVector<unsigned int>* scoreOfPopulation,
                              unsigned int itemsNo, bool sortBetter)
{
    /*
    //for m times we select best of the population
    //first time we select the 1st and put it into 1st place
    //second time we select the 1st best of the remaining and put it at 2nd place
    //and so on...
    */
    int bestPosition[omp_get_max_threads()];

    //for(int pos=0; pos<this->crossover+this->newIndividualsNumber; pos++)
    //int pos=sortBetter?population->size()-itemsNo:0;
    //unsigned int maxItems=sortBetter?population->size():itemsNo;
    for(int pos=0; pos<itemsNo; pos++)
    {

        for(int threadIndex=0; threadIndex<omp_get_max_threads(); threadIndex++)
            bestPosition[threadIndex]=pos;
        bool sortingCondition;
        #pragma omp parallel for private(sortingCondition)
        for(int itempos=pos+1; itempos<population->size(); itempos++)
        {
            //bool sortingCondition;
            if(sortBetter)
                sortingCondition=scoreOfPopulation->at(bestPosition[omp_get_thread_num()])
                        <scoreOfPopulation->at(itempos);
            else
                sortingCondition=scoreOfPopulation->at(bestPosition[omp_get_thread_num()])
                        >scoreOfPopulation->at(itempos);

            if(sortingCondition)
                bestPosition[omp_get_thread_num()]=itempos;
            //if (bestPosition==itempos)
            //    cout<<"found better!"<<endl;
        }
        //swapping both scoreOfPopulation and population

        int bestPos=bestPosition[0];
        //fare una ricerca del massimo all'interno dell'array
        //delle posizioni migliori
        for(int i=1; i<omp_get_max_threads(); i++)
        {    if(sortBetter)
                sortingCondition=scoreOfPopulation->at(bestPos)
                        <scoreOfPopulation->at(bestPosition[i]);
            else
                sortingCondition=scoreOfPopulation->at(bestPos)
                        >scoreOfPopulation->at(bestPosition[i]);

            if(sortingCondition)
                bestPos=bestPosition[i];
         }

        if(bestPos!=pos) //only if necessary
        {
            unsigned int winnerScore=scoreOfPopulation->at(bestPos);
            scoreOfPopulation->replace(bestPos, scoreOfPopulation->at(pos));
            scoreOfPopulation->replace(pos, winnerScore);
            Path winnerPath=population->at(bestPos);
            population->replace(bestPos, population->at(pos));
            population->replace(pos, winnerPath);
        }
    }
}


void
GeneticEngine::generateChildren(QVector<Path>* population, QVector<Path>* children)
{
    srand(0);
    for(unsigned int childNo=0; childNo<this->crossover/2; childNo++)
    {
        //RAND_MAX division needed!
        //#pop*rand()/RAND_MAX --> #pop*(a number between 0 and 1) --> result<#pop (or at least equal to)
        Path firstParent=population->at((population->size()*rand())/RAND_MAX);
        Path secondParent=population->at((population->size()*rand())/RAND_MAX);
        unsigned int crossoverPoint=rand()%this->gih->getNodes().size();

        //before change was:
        //Path firstChild, secondChild;
        Path firstChild=this->gih->generateDefaultPath(),
                secondChild=this->gih->generateDefaultPath();
        for(unsigned int item=0; item<this->gih->getNodes().size(); item++)
        {
            firstChild.addName(firstParent.getNameByPoint(item));
            secondChild.addName(firstParent.getNameByPoint(item));
            firstChild.appendPoint(item<crossoverPoint?
                                       firstParent.getPath().at(item):
                                       secondParent.getPath().at(item));
            secondChild.appendPoint(item<crossoverPoint?
                                       secondParent.getPath().at(item):
                                       firstParent.getPath().at(item));
        }

        //cout<<"DEBUG into generateChildren, printing children"<<endl;
        //firstChild.print();
        //secondChild.print();

        children->append(firstChild);
        children->append(secondChild);
    }
}

void
GeneticEngine::killIndividualsWithLowFitness(QVector<Path>* population)
{
    population->remove(0, this->crossover+this->newIndividualsNumber);
}

QVector<Path>
GeneticEngine::getBestPaths()
{
    QVector<Path> *population=new QVector<Path>;
    this->initializePopulation(population, this->populationDimension);
    QVector<unsigned int> *scoreOfPopulation=new QVector<unsigned int>(population->size());
    double average=0, start, end;
    QVector<Path> *children=new QVector<Path>;
    for(unsigned int times=0; times<this->generations; times++)
    {
        start=omp_get_wtime();
        cout<<"generation #"<<times<<endl;


        if(times)
        {
            cout<<"mutation of some individuals"<<endl;

            //this->mutatePopulation(population);
            this->mutatePopulation(children);
            cout<<"end of the mutation"<<endl;
        }

        //all can die. who's next? Let's see...
        cout<<"evaluation."<<endl;
        double start_eval=omp_get_wtime();
        if(times==0)
        {
            this->evaluatePopulation(population, scoreOfPopulation,
                                 this->populationDimension);
            //for(unsigned int i=0; i<this->populationDimension; i++)
            //{
            //    Path p=population->at(i); p.print();
            //}
        }
        else
            //we have already evaluated survived individuals
            this->evaluatePopulation(population, scoreOfPopulation,
                                 this->crossover+this->newIndividualsNumber);
        double end_eval=omp_get_wtime();
        cout<<"tempo per la valutazione: "<<end_eval-start_eval<<endl;


        //cout<<"starting population stats"<<endl;
        //this->populationStats(population, scoreOfPopulation);


        //we just take best individuals...
        cout<<"sorting (D:) population"<<endl;
        double start_sort=omp_get_wtime();
        //mmm... I think we need a smarter sort algorithm. maybe in PaRR2.
        this->sortPopulation(population, scoreOfPopulation, population->size());
        double end_sort=omp_get_wtime();
        cout<<"tempo per il sort: "<<end_sort-start_sort<<endl;
        //... and kill who is not strong enough to survive.
        if(times+1!=this->generations)
        {

            children=new QVector<Path>;
            //people are mating.
            cout<<"people are mating."<<endl;
            double start_gen=omp_get_wtime();
            this->generateChildren(population, children);
            double end_gen=omp_get_wtime();
            cout<<"tempo per la generazione dei figli: "<<end_gen-start_gen<<endl;
            cout<<"kill people not strong enough to survive!"<<endl;
            this->killIndividualsWithLowFitness(population);
            //now replacing died with fresh meat.
            cout<<"replacing died with children"<<endl;
            for(unsigned int childIndex=0; childIndex<(unsigned)children->size(); childIndex++)
            {
                population->push_front(children->at(childIndex));
            }
            cout<<"foreign people are coming to town. adding them to population!"<<endl;
            for(unsigned int foreignIndex=0; foreignIndex<this->newIndividualsNumber; foreignIndex++)
                population->push_front(this->generateRandomPath(this->gih->getNodes().size()));
        }
        end=omp_get_wtime();
        cout<<end-start<<"seconds were spent on the calculation of this generation"<<endl;
        average+=(end-start);
    }
    //stats info (debugging/profiling purposes)
    average/=this->generations;
    cout<<"average time for generation: "<<average<<", generations: ";
    cout<<this->generations<<endl;
    return *population;
}

void
GeneticEngine::populationStats(QVector<Path> *population, QVector<unsigned int> *scoreOfPopulation)
{
    unsigned int positionsNo=((this->gih->getAcceptedConstraints().size()+
                              this->gih->getRejectedConstraints().size())*
            this->gih->getNodes().size())+1;
    //QVector<unsigned int> scores(positionsNo);
    unsigned int *scores=(unsigned int*)malloc(positionsNo* sizeof(unsigned int));
#pragma omp parallel for
    for(int clear_index=0; clear_index<population->size(); clear_index++)
    {
        scores[clear_index]=0;
    }
    //scores.fill(0);
#pragma omp parallel for
    for(int i=0; i<scoreOfPopulation->size(); i++)
    {
        //cout<<"item #"<<i<<endl;
        //Path lolpath=population->at(i);
        //lolpath.print();
        //cout<<"score: "<<scoreOfPopulation->at(i)<<endl;
        //scores.replace(scoreOfPopulation->at(i), scores.at(scoreOfPopulation->at(i)));
        #pragma omp critical
        scores[scoreOfPopulation->at(i)]+=1;
    }
    //aggiungere, se possibile, anche una statistica sulle frequenze
    //assolute e relative.
    cout<<"starting enumeration"<<endl;
    for(unsigned int index=0; index<positionsNo; index++)
    {
        if(scores[index]!=0)
            cout<<"there are #"<<scores[index]<<" items that has score "<<index<<endl;
    }
}


int
GeneticEngine::compareSolutions(Path first, Path last)
{
    /*
      it lets you avoid writing boilerplate code
      in order to compare solutions using GeneticEngine::evaluatePopulation

      it has a behaviour like Java's Object.compareTo(Object, Object):
      -1 if first's score < last's score
      0 if first's score == last's score
      1 if first's score > last's score
    */

    QVector<Path> solutionsVector(2);
    solutionsVector.append(first); solutionsVector.append(last);
    QVector<unsigned int> scores(2);
    scores.fill(0);

    this->evaluatePopulation(&solutionsVector, &scores, 2);

    if(scores.at(0)>scores.at(1))
        return 1;
    else if(scores.at(0)==scores.at(1))
        return 0;
    return -1;
}
