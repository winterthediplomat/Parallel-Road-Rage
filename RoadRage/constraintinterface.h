#ifndef CONSTRAINTINTERFACE_H
#define CONSTRAINTINTERFACE_H

#include "constraint.h"
#include <QDialog>
//#include <QAction>

class GraphInformationHandler; //forward declaration

class ConstraintInterface
{
protected:
    GraphInformationHandler *gih;

public:
    ConstraintInterface(GraphInformationHandler *gih);
    //virtual ~ConstraintInterface(){};

    virtual bool hasUI();

    //virtual bool isReject()=0;
    virtual Constraint* getConstraintObj();
    virtual QDialog* getDialog();
    //virtual QString name();

    /*
    virtual QAction* constraintAction();
    virtual void constraintSlot();
    */
};

#endif // CONSTRAINTINTERFACE_H
