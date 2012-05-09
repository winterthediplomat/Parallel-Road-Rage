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

    QVector<Path> getBestPaths();

private:

    void initializePopulation(QVector<Path> *population, unsigned int championDim=1067);
    void evaluatePopulation(QVector<Path> *population, QVector<unsigned int> *scoreOfPopulation, unsigned int howManyToEvaluate);

    void sortPopulation(QVector<Path> *population, QVector<unsigned int> *scoreOfPopulation,
                        unsigned int itemsNo=-1, bool sortBetter=false);
    void killIndividualsWithLowFitness(QVector<Path>* population);
    void generateChildren(QVector<Path>* population, QVector<Path>* children);

    //needed by ::initializePopulation
    Path generateRandomPath(unsigned int solutionLength);
    //Path convertAddressToPath(unsigned int address, unsigned int itemsNo);

    void populationStats(QVector<Path>* population, QVector<unsigned int>* scoreOfPopulation);

    float mutationProbability;
    unsigned int crossover;
    unsigned int generations;
    unsigned int populationDimension;
    unsigned int newIndividualsNumber;
    GraphInformationHandler *gih;
};

#endif // GENETICENGINE_H
