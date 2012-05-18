#include <iostream>
#include "btsolver.h"

#ifdef _OPENMP
#include <omp.h> //OpenMP routines
#endif
using namespace std;


BTSolver::BTSolver() : Solver()
{
    this->acceptConstraints=new QVector<Constraint*>;
    this->rejectConstraints=new QVector<Constraint*>;
}

void BTSolver::addNewSolutions(Path startSolution)
{

    cout<<"adding a solution!"<<startSolution.getNodes()<<endl;
    for(unsigned int i=0; i<startSolution.getNodes(); i++)
    {
        Path newsol(startSolution.getNodes(), startSolution.getPath());
        for(unsigned int j=0; j<startSolution.getNodes();j++)
            newsol.addName(startSolution.getNameByPoint(j));
        newsol.appendPoint(i);
        #pragma omp critical
        {this->candidateSolutionsStack->push(newsol);}
    }
}

void BTSolver::getSolutions(Path startSolution, QVector<Path> *solutions)
{
    //QVector<Path>* solutions=new QVector<Path>();
    this->candidateSolutionsStack=new QStack<Path>();

    //initialize stack of candidate solutions with a solution
    //that could be empty of partially fulled.
    candidateSolutionsStack->push(startSolution);
    unsigned int solutionCounter=0;
    //find solutions
    Path actualCandidate=Path(0);
    //bool isRetrieved;
    //QVector<Path> *nexts;

#pragma omp parallel private(actualCandidate/*, nexts*/) num_threads(2)
{

    #pragma omp master
    {
        //useful debug options...
        cout<<"# max threads: "<<omp_get_max_threads()<<endl;
        cout<<"# threads: "<<omp_get_num_threads()<<endl;
    }
    do
    {

        //get first element of the stack w/o deleting it

        //Path actualCandidate=candidateSolutionsStack->top();
        //candidateSolutionsStack->pop(); //delete first element of the stack


       #pragma omp critical
       {
           cout<<"dentro! numero soluzioni parziali salvate: "<<candidateSolutionsStack->size()<<endl;
           //isRetrieved=true;
           //cout<< omp_get_thread_num() <<"retrieving a solution..."<<endl;
           if(!candidateSolutionsStack->isEmpty())
           {
               //cout<<omp_get_thread_num()<<"retrieved!"<<endl;
               actualCandidate=candidateSolutionsStack->top();
               candidateSolutionsStack->pop();
               //cout<<"retrieved!";
               //actualCandidate.print();
           }
           else
           {
               //cout<<"not retrieved, creating a path with 0 max length"<<endl;
               actualCandidate=Path(0);
               //cout<<"not retrieved"<<endl;
               //isRetrieved=false;
               //actualCandidate=NULL;
           }
       }

       //cout<<&actualCandidate<<endl;

       if(actualCandidate.getNodes()!=0 && !this->rejectSolution(actualCandidate))
       {
           //cout<<"ok, this solution is interesting..."<<endl;
           if(!this->acceptSolution(actualCandidate))
           {
                //#pragma omp critical
                addNewSolutions(actualCandidate);
                /*
                #pragma omp critical
                {
                    nexts=new QVector<Path>();
                    actualCandidate.nextCandidates(nexts);
                    for(int i=0; i<nexts->size(); i++)
                    {
                        if(nexts->isEmpty() && nexts->size()==0)
                            cout<<"wat?"<<endl;
                        candidateSolutionsStack->push(nexts->at(i));
                    }
                    delete nexts;
                    nexts=NULL; //free space of next candidate solutions
                }   //end #pragma omp critical
                */
             }

            else
            {
                //save solution
                solutionCounter++;
                #pragma omp critical
                {
                    //actualCandidate.print();
                    solutions->append(actualCandidate);
                }
            }
        }
        else
        {
            //cout<<"rejected solution! ";
            //actualCandidate.print();
            /*for(int pos=0; pos<actualCandidate.getPath().size();
                pos++)
                cout<<actualCandidate.getPath().at(pos);
            cout<<endl;*/
        }


    //barrier is needed to avoid death of other threads,
    //so the first thread that catches the solution can put
    //new solutions while others wait there, and
    //candidateSolutionsStack is not empty.
    #pragma omp barrier
    cout<<"ok, over the barrier! thread_num:"<<omp_get_thread_num()<<endl;
    }while(!candidateSolutionsStack->isEmpty());
} //end #pragma omp parallel
    cout<<"fuori"<<endl;
    //freein' memory
    delete candidateSolutionsStack;
    cout<<"solutions->size()=="<<solutions->size()<<" solutionCounter="<<solutionCounter<<endl;
    //return solutions;
}

/*
bool BTSolver::rejectSolution(Path candidate)
{
    bool isRejected=false;
#pragma omp parallel for
    for(int i=0; i<this->rejectConstraints->size(); i++)
    {
        //this->rejectConstraints->at(i)->printName();
        if(!this->rejectConstraints->at(i)->isRespected(candidate))
        {
            //cout<<"not respected constraint at "<<i<<"th position!"<<endl;
            isRejected=true;
        }
    }
    return isRejected;
}

bool BTSolver::acceptSolution(Path candidate)
{
    bool isAccepted=false;
#pragma omp parallel for
    for(int i=0; i<this->acceptConstraints->size(); i++)
    {
        if(this->acceptConstraints->at(i)->isRespected(candidate))
            isAccepted=true;
    }
    return isAccepted;
}

void BTSolver::addAcceptConstraint(Constraint *newConstraint)
{this->acceptConstraints->push_back(newConstraint);}

void BTSolver::addRejectConstraint(Constraint *newConstraint)
{this->rejectConstraints->push_back(newConstraint);}
*/
