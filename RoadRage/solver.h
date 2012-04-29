#ifndef SOLVER_H
#define SOLVER_H

//#include <QStack>
//#include <QVector>
#include <QVector>
#include <stack>
#include "constraint.h"
#include "path.h"
//#include "backtrackinglibrary.cpp"
#include "graphinformationhandler.h"
//class GraphInformationHandler;

class Solver
{
protected:
    QVector<Constraint*> *acceptConstraints;
    QVector<Constraint*> *rejectConstraints;

public:
    Solver();

    void addAcceptConstraint(Constraint* newConstraint);
    void addRejectConstraint(Constraint* newConstraint);
    //void removeConstraint(Constraint* constraint);

    //QVector<Path> *getSolutions(Path startSolution);
    //virtual void getSolutions(Path startSolution, QVector<Path> *solutions);
    //void getSolutions(Path startSolution, QVector<Path> *solutions);
    //Path getShortestSolution(Path startingSolution);
    bool rejectSolution(Path candidate);

    bool acceptSolution(Path candidate);

};

#endif // SOLVER_H
