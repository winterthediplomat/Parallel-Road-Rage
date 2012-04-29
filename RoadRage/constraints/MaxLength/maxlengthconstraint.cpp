#include "maxlengthconstraint.h"
#include "iostream"
using namespace std;

MaxLengthConstraint::MaxLengthConstraint()
{
    this->setMaxLength(0);
}

bool MaxLengthConstraint::isRespected(Path candidate)
{
    return candidate.getPath().size()==this->maxLength;
}

bool MaxLengthConstraint::isEqualTo(Constraint *comparingConstraint)
{
    return false;
}

void MaxLengthConstraint::printName()
{
    //cout<<"Max Length! length: "<<this->maxLength<<endl;
    cout<<this->generateJSON().toStdString()<<endl;
}

void MaxLengthConstraint::setMaxLength(int maxLength)
{
    this->maxLength=maxLength;
}

/*
Constraint* MaxLengthConstraint::createInstance()
{
    return new MaxLengthConstraint();
}
*/

QString MaxLengthConstraint::generateJSON()
{
    return QString(
                "{'name': '%1', 'values':{'maxlength':%2}}"
                ).arg("MaxLengthConstraint").arg(this->maxLength);
}


unsigned int
MaxLengthConstraint::calculateSolutionScore(Path candidate)
{
    return this->isRespected(candidate)?this->maxLength:0;
}
