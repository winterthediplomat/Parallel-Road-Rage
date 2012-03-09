#ifndef BACKTRACKINGLIBRARY_H
#define BACKTRACKINGLIBRARY_H

//#include "BackTrackingLibrary_global.h"
#include <QStack>
#include <QVector>
#include "constraint.h"
#include "path.h"
#include "solver.h"
//#include "backtrackinglibrary.cpp"


class BTSolver : public Solver
{
    /*
private:
    QVector<Constraint*> *acceptConstraints;
    QVector<Constraint*> *rejectConstraints;
*/
private:
    QStack<Path> *candidateSolutionsStack;

    void addNewSolutions(Path startPath);

public:
    BTSolver();

    //void addAcceptConstraint(Constraint* newConstraint);
    //void addRejectConstraint(Constraint* newConstraint);
    ////void removeConstraint(Constraint* constraint);

    ////QVector<Path> *getSolutions(Path startSolution);
    void getSolutions(Path startSolution, QVector<Path> *solutions);

    //Path getShortestSolution(Path startSolution);

    //bool rejectSolution(Path candidate);
    //bool acceptSolution(Path candidate);

};

#endif // BACKTRACKINGLIBRARY_H
