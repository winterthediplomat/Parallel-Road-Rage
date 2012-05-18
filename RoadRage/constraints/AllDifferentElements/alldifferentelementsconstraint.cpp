#include "alldifferentelementsconstraint.h"
#include "iostream"
#include <set>
using namespace std;

AllDifferentElementsConstraint::AllDifferentElementsConstraint() : Constraint()
{
}

bool AllDifferentElementsConstraint::isRespected(Path candidate)
{
    if(&candidate==0)
        return false;

    int dimension=candidate.getPath().size();
    //cout<<"DEBUG@AllDifferentElementsConstraint::isRespected: solution is: ";
    //candidate.print();
    //cout<<"DEBUG@AllDifferentElementsConstraint::isRespected: dimension is: "<<dimension<<endl;
    if(dimension<2) return true;

    for(unsigned int i=0; i<candidate.getNodes(); i++)
    {
        //int items=0;
        if(candidate.getPath().count(i)>1) //max 0 or 1 times
            //items++;
            return false;

        //for(unsigned int j=0; j<candidate.getPath().size(); j++)
        //    if(candidate.getPath().at(j)==i)
        //        items++;
        //cout<<"DEBUG@AllDifferentElementsConstraint::isRespected: "<<i<<" items=="<<items<<endl;
        //if(items>1)
        //    return false;
    }
    return true;
}

bool AllDifferentElementsConstraint::isEqualTo(Constraint* comparingConstraint)
{
    return false;
}

void AllDifferentElementsConstraint::printName()
{
    //cout<<"All Different Elements!"<<endl;
    cout<<this->generateJSON().toStdString()<<endl;
}

/*
Constraint* AllDifferentElementsConstraint::createInstance()
{
    return new AllDifferentElementsConstraint();
}
*/

QString AllDifferentElementsConstraint::generateJSON()
{
    return QString(
                "{'name':'%1', 'values':{}}"
                ).arg("AllDifferentElementsConstraint");
}

unsigned int
AllDifferentElementsConstraint::calculateSolutionScore(Path candidate)
{
    int dimension=candidate.getPath().size();
    unsigned int score=0;
    if(dimension<2) return dimension;

    for(unsigned int i=0; i<candidate.getNodes(); i++)
    {
        //if(candidate.getPath().count(i)<2)
        if(candidate.getPath().count(i)==1)
            score++;
    }

    if(score==1) score=0;
    return score;
}
