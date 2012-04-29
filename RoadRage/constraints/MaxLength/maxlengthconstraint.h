#ifndef MAXLENGTHCONSTRAINT_H
#define MAXLENGTHCONSTRAINT_H

#include "constraint.h"

class MaxLengthConstraint : public Constraint
{
private:
    int maxLength;
public:
    MaxLengthConstraint();

    void setMaxLength(int maxLength);
    virtual bool isRespected(Path candidate);
    virtual bool isEqualTo(Constraint* comparingConstraint);
    virtual void printName();
    virtual QString generateJSON();
    //virtual Constraint* createInstance();
    virtual unsigned int calculateSolutionScore(Path candidate);
};

#endif // MAXLENGTHCONSTRAINT_H
