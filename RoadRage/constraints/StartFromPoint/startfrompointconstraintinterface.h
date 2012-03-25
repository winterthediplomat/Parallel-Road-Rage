#ifndef STARTFROMPOINTCONSTRAINTINTERFACE_H
#define STARTFROMPOINTCONSTRAINTINTERFACE_H

#include "constraintinterface.h"
#include "startfrompointconstraint.h"

class StartFromPointConstraintInterface : public ConstraintInterface
{
public:
    StartFromPointConstraintInterface(GraphInformationHandler* gih);

    virtual StartFromPointConstraint* getConstraintObj();
    virtual ConstraintDialog* getDialog();
};

#endif // STARTFROMPOINTCONSTRAINTINTERFACE_H
