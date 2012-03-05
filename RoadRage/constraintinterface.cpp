#include "constraintinterface.h"
#include "iostream"
using namespace std;

ConstraintInterface::ConstraintInterface(GraphInformationHandler *gih)
{
    this->gih=gih;
}

QDialog* ConstraintInterface::getDialog()
{
    return 0;
}

Constraint* ConstraintInterface::getConstraintObj()
{
    cout<<"someone is calling base class method. not sure if trolling."<<endl;
    return 0;
}

bool ConstraintInterface::hasUI()
{
    return false;
}

/*
bool ConstraintInterface::isReject()
{
    return false;
}
*/

/*
QString ConstraintInterface::name()
{
    return "";
}*/
/*
QAction* ConstraintInterface::constraintAction()
{
    return new QAction(this->name(), 0);
}

void ConstraintInterface::constraintSlot()
{
    if(this->hasUI())
        this->getDialog()->exec();
}
*/
