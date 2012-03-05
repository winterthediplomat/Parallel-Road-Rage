#include "alldifferentelementsconstraintinterface.h"

AllDifferentElementsConstraintInterface::AllDifferentElementsConstraintInterface(GraphInformationHandler *gih):
    ConstraintInterface(gih)
{
    cout<<"address of given GIH obj in adeci: "<<&gih<<endl;
}


AllDifferentElementsConstraint *AllDifferentElementsConstraintInterface::getConstraintObj()
{
    return new AllDifferentElementsConstraint();
}

bool AllDifferentElementsConstraintInterface::hasUI()
{
    return true;
}
