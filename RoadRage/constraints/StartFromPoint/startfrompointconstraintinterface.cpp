#include "startfrompointconstraintinterface.h"

StartFromPointConstraintInterface::StartFromPointConstraintInterface(
        GraphInformationHandler *gih): ConstraintInterface(gih)
{
    this->gih=gih;
}

ConstraintDialog *StartFromPointConstraintInterface::getDialog()
{
    return NULL;
}

StartFromPointConstraint*
StartFromPointConstraintInterface::getConstraintObj()
{
    StartFromPointConstraint* constraintObj=new StartFromPointConstraint();
    constraintObj->setFirstPoint(0);
    return constraintObj;
}

