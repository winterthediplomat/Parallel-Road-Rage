#ifndef ALLDIFFERENTELEMENTSCONSTRAINT_H
#define ALLDIFFERENTELEMENTSCONSTRAINT_H

#include "constraint.h"
#include "path.h"

class AllDifferentElementsConstraint : public Constraint
{
public:
    AllDifferentElementsConstraint();

    virtual bool isRespected(Path candidate);
    virtual bool isEqualTo(Constraint *comparingConstraint);
    virtual void printName();
    virtual QString generateJSON();
    //virtual Constraint* createInstance();
    virtual unsigned int calculateSolutionScore(Path candidate);
};

#endif // ALLDIFFERENTELEMENTSCONSTRAINT_H
