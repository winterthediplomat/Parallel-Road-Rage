#include "startfrompointconstraint.h"

StartFromPointConstraint::StartFromPointConstraint()
{
}

void
StartFromPointConstraint::setFirstPoint(const unsigned int firstPoint)
{
    this->firstPoint=firstPoint;
}

unsigned int
StartFromPointConstraint::getFirstPoint()
{
    return this->firstPoint;
}

void
StartFromPointConstraint::printName()
{
    cout<<"StartFromPointConstraint"<<endl;
}

bool
StartFromPointConstraint::isRespected(Path candidate)
{
    if(candidate.getPath().size()<1)
        return true;
    return candidate.getPath().at(0)==this->firstPoint;
}

QString
StartFromPointConstraint::generateJSON()
{
    return QString(
                "{'name': '%1', 'values':{'firstpoint':%2}}"
                ).arg("StartFromPoint").arg(this->firstPoint);
}

unsigned int
StartFromPointConstraint::calculateSolutionScore(Path candidate)
{
    return this->isRespected(candidate)?candidate.getNodes():0;
}
