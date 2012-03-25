#include "constraints/AllConnectedToEachOther/allconnectedtoeachotherconstraintinterface.h"
#include <iostream>

AllConnectedToEachOtherConstraintInterface::AllConnectedToEachOtherConstraintInterface(
        GraphInformationHandler *gih): ConstraintInterface(gih)
{
    this->gih=gih;
    cout<<"address of GIH obj in AllConnectedToEachOtherConstraintInterface="<<this->gih<<endl;
}


bool AllConnectedToEachOtherConstraintInterface::hasUI()
{
    return false;
}

ConstraintDialog *AllConnectedToEachOtherConstraintInterface::getDialog()
{
    return NULL;
}

AllConnectedToEachOther*
AllConnectedToEachOtherConstraintInterface::getConstraintObj()
{
    AllConnectedToEachOther *obj=new AllConnectedToEachOther();
    obj->setGIH(this->gih);
    cout<<"AllConnectedToEachOtherConstraintInterface::getConstraintObj"<<endl;
    cout<<"address of GIH obj="<<gih<<endl;
    return obj;
}
