#ifndef ALLCONNECTEDTOEACHOTHER_H
#define ALLCONNECTEDTOEACHOTHER_H

#include "constraint.h"
#include <QString>
#include "graphinformationhandler.h"

class AllConnectedToEachOther : public Constraint
{
public:
    AllConnectedToEachOther();

    //virtual void setGIHobj(GraphInformationHandler *gih);
    void setGIH(GraphInformationHandler *gih);
    virtual bool isRespected(Path candidate);
    virtual bool isEqualTo(Constraint* comparingConstraint);
    virtual void printName();
    virtual QString generateJSON();
    virtual bool needsGIH();

    virtual unsigned int calculateSolutionScore(Path candidate);

/*
private:
    GraphInformationHandler *gih;
*/
};

#endif // ALLCONNECTEDTOEACHOTHER_H
