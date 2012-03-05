#ifndef LASTPOINTCONNECTEDTOFIRSTCONSTRAINTINTERFACE_H
#define LASTPOINTCONNECTEDTOFIRSTCONSTRAINTINTERFACE_H

#include "constraintinterface.h"
#include "constraints/LastPointConnectedToFirst/lastpointconnectedtofirstconstraint.h"

class LastPointConnectedToFirstConstraintInterface : public ConstraintInterface
{
public:
    LastPointConnectedToFirstConstraintInterface(
            GraphInformationHandler *gih);

    virtual bool hasUI();

    virtual LastPointConnectedToFirstConstraint* getConstraintObj();
    virtual QDialog* getDialog();
};

#endif // LASTPOINTCONNECTEDTOFIRSTCONSTRAINTINTERFACE_H
