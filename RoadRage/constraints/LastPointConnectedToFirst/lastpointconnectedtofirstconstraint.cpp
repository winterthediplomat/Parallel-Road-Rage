#include "lastpointconnectedtofirstconstraint.h"
#include "link.h"

LastPointConnectedToFirstConstraint::LastPointConnectedToFirstConstraint()
{
    this->gih=NULL;
}

QString
LastPointConnectedToFirstConstraint::generateJSON()
{
    return QString("{'name':'%1', 'values':{}}").arg("LastPointConnectedToFirst");
}

void
LastPointConnectedToFirstConstraint::printName()
{
    cout<<"Last Point Connected to First"<<endl;
}

bool
LastPointConnectedToFirstConstraint::isRespected(Path candidate)
{
    if(candidate.getPath().size()<2)
        return false;
    //cout<<"LastPointConnectedToFirstConstraint"<<endl;
    //candidate.print();
    QString firstNodeName=candidate.getNameByPoint(candidate.getPath().at(0));
    QString lastNodeName=candidate.getNameByPoint(candidate.getPath().at(candidate.getPath().size()-1));
    Link* linkFromFirstToLast=this->gih->getTheLinkByNodes(
                this->gih->getNodeByText(lastNodeName),
                this->gih->getNodeByText(firstNodeName)
                );
    if(!linkFromFirstToLast)
    {
        //cout<<"no links from "<<firstNodeName.toStdString()<<" to "<<lastNodeName.toStdString()<<endl;
        return false;
    }
    else
    {
        //candidate.print();
        //cout<<"a link from "<<lastNodeName.toStdString()<<" to "<<firstNodeName.toStdString()<<": link="<<linkFromFirstToLast<<endl;
        //cout<<"distance from points: "<<linkFromFirstToLast->distance()<<endl;
        return linkFromFirstToLast->distance()!=0 && linkFromFirstToLast->distance()!=INT_MAX;
    }
}

unsigned int
LastPointConnectedToFirstConstraint::calculateSolutionScore(Path candidate)
{
    return this->isRespected(candidate)?candidate.getNodes():0;
}
