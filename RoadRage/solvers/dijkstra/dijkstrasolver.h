#ifndef DIJKSTRASOLVER_H
#define DIJKSTRASOLVER_H

#include "solver.h"

class DijkstraSolver : public Solver
{
private:
    GraphInformationHandler *gih;

public:
    DijkstraSolver();
    void getSolutions(QString startNode, QString endNode,
                      Path &fasterPath, unsigned int &distanceOfPath);

    void setGIH(GraphInformationHandler* gih);
};

#endif // DIJKSTRASOLVER_H
