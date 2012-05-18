#ifndef GENETICENGINE_H
#define GENETICENGINE_H

#include "solver.h"
class GeneticEngine : public Solver
{
public:
    GeneticEngine(unsigned int generations);

    void setGIH(GraphInformationHandler *gih);
    void setMutationProbability(float mutProb);
    float getMutationProbability();
    void setCrossover(unsigned int crossover);
    unsigned int getCrossover();
    void setPopulationDimension(unsigned int dimension);
    unsigned int getPopulationDimension();
    void setNewIndividualsNumber(unsigned int newIndividuals);
    unsigned int getNewIndividualsNumber();
    void setElitismNumber(unsigned int elitists);
    unsigned int getElitismNumber();

    QVector<Path> getBestPaths();

private:

    void initializePopulation(QVector<Path> *population, unsigned int championDim=1067);
    void evaluatePopulation(QVector<Path> *population, QVector<unsigned int> *scoreOfPopulation, unsigned int howManyToEvaluate);

    void sortPopulation(QVector<Path> *population, QVector<unsigned int> *scoreOfPopulation,
                        unsigned int itemsNo=-1, bool sortBetter=false);
    void killIndividualsWithLowFitness(QVector<Path>* population);
    void generateChildren(QVector<Path>* population, QVector<Path>* children);
    void mutatePopulation(QVector<Path>* population);

    //needed by ::initializePopulation
    Path generateRandomPath(unsigned int solutionLength);
    //Path convertAddressToPath(unsigned int address, unsigned int itemsNo);

    void populationStats(QVector<Path>* population, QVector<unsigned int>* scoreOfPopulation);

    int compareSolutions(Path first, Path last);

    float mutationProbability;
    unsigned int crossover;
    unsigned int generations;
    unsigned int populationDimension;
    unsigned int newIndividualsNumber;
    unsigned int elitistsNumber;
    GraphInformationHandler *gih;
};

#endif // GENETICENGINE_H
