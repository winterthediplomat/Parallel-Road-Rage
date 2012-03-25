#include "maxlengthconstraintinterface.h"
#include "iostream"
#include "node.h"

using namespace std;
MaxLengthConstraintInterface::MaxLengthConstraintInterface(GraphInformationHandler *gih) :
    ConstraintInterface(gih)
{
    cout<<"address of given GIH obj in MaxLengthConstraintInterface: "<<gih<<endl;
    Node *trollNode=gih->getNodeByText("Node 1");
    cout<<"trollNode address: "<<trollNode<<endl;
}

MaxLengthConstraint *MaxLengthConstraintInterface::getConstraintObj()
{
    return new MaxLengthConstraint();
}

ConstraintDialog* MaxLengthConstraintInterface::getDialog()
{
    cout<<"yeah, you're MaxLengthConstraintInterface!!!!1"<<endl;
    return new MaxLengthConstraintDialog(this->gih, 0);
}

bool MaxLengthConstraintInterface::hasUI()
{
    return true;
}
