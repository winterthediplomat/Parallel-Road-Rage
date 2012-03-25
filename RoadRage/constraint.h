#ifndef CONSTRAINT_H
#define CONSTRAINT_H

#include "path.h"
#include <QString>

class GraphInformationHandler;
//include "graphinformationhandler.h"

class Constraint
{
protected:
    GraphInformationHandler *gih;
public:
    Constraint();

    /*
      all these methods must be overrided!
    */
    virtual bool isRespected(Path candidate);
    virtual bool isEqualTo(Constraint* comparingConstraint);
    virtual void printName();
    virtual QString generateJSON();
    //interface of constraints have been created for a reason, don't you say?
    //virtual bool needsGIH();
    virtual void setGIH(GraphInformationHandler *gih);
    // void setGIH(GraphInformationHandler *gih);
    //virtual Constraint* createInstance();
};

#endif // CONSTRAINT_H
