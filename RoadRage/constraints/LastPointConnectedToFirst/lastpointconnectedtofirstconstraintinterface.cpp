#include "lastpointconnectedtofirstconstraintinterface.h"

LastPointConnectedToFirstConstraintInterface::LastPointConnectedToFirstConstraintInterface(GraphInformationHandler *gih) :
    ConstraintInterface (gih)
{
    this->gih=gih;
}

QDialog* LastPointConnectedToFirstConstraintInterface::getDialog()
{
    return NULL;
}

LastPointConnectedToFirstConstraint*
LastPointConnectedToFirstConstraintInterface::getConstraintObj()
{
    LastPointConnectedToFirstConstraint* obj=
            new LastPointConnectedToFirstConstraint();
    obj->setGIH(this->gih);
    return obj;
}

bool
LastPointConnectedToFirstConstraintInterface::hasUI()
{
    return false;
}
