#ifndef LASTPOINTCONNECTEDTOFIRSTCONSTRAINT_H
#define LASTPOINTCONNECTEDTOFIRSTCONSTRAINT_H

#include "constraint.h"
#include "graphinformationhandler.h"


class LastPointConnectedToFirstConstraint : public Constraint
{
public:
    LastPointConnectedToFirstConstraint();

    virtual bool isRespected(Path candidate);
    //virtual bool isEqualTo(Constraint* comparingConstraint);
    virtual void printName();
    virtual QString generateJSON();
    //interface of constraints have been created for a reason, don't you say?
    //virtual bool needsGIH();
    //virtual void setGIH(GraphInformationHandler *gih);
    // void setGIH(GraphInformationHandler *gih);
    //virtual Constraint* createInstance();
    virtual unsigned int calculateSolutionScore(Path candidate);
};

#endif // LASTPOINTCONNECTEDTOFIRSTCONSTRAINT_H
