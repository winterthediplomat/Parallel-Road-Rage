//#include "allconnectedtoeachother.h"
#include "constraints/AllConnectedToEachOther/allconnectedtoeachother.h"
#include <QtGlobal>
#include "iostream"
#include "link.h"
using namespace std;

AllConnectedToEachOther::AllConnectedToEachOther()
{
    //cout<<"address of AllConnectedToEachOther: "<<this<<endl;
}

void AllConnectedToEachOther::setGIH(GraphInformationHandler *gih)
{
    //cout<<gih<<endl;
    this->gih=gih;
    //cout<<"saved address of gih is:"<<this->gih<<endl;
    //Node *lol=this->gih->getNodeByText("Node 1");
    //cout<<"lolnode has address: "<<lol<<endl;
    //Q_ASSERT_X(this->gih==gih, "AllConnectedToEachOther::setGIHobj", "given address and saved one are not equal!");
}

QString AllConnectedToEachOther::generateJSON()
{
    return QString(
                "{'name':%1, 'values':{}}"
                ).arg("'AllConnectedToEachOther'");
}


void AllConnectedToEachOther::printName()
{
    cout<<"AllConnectedToEachOther"<<endl;
}

bool AllConnectedToEachOther::isRespected(Path candidate)
{
    //needed in the past, when not retrieved solutions
    //got a NULL adress
    //if(&candidate==0)
    //    return false;
    if(candidate.getPath().size()<2)
        return true;

    unsigned int firstNode, secondNode;
    QString firstNodeName, secondNodeName;
    Link* the_link=NULL;
    bool allConnected=true;
    int candidateNodeNum=candidate.getPath().size();

//#pragma omp parallel for
    for(int index=0; index<candidateNodeNum-1; index++)
    {
        firstNode=candidate.getPath().at(index);
        secondNode=candidate.getPath().at(index+1);
        //cout<<"firstNode is:"<<firstNode<<"\t"<<"secondNode is:"<<secondNode<<endl;
        firstNodeName=candidate.getNameByPoint(firstNode);
        secondNodeName=candidate.getNameByPoint(secondNode);
        //cout<<"firstNodeName is:"<<firstNodeName.toStdString()<<endl;
        //cout<<"secondNodeName is:"<<secondNodeName.toStdString()<<endl;
        //cout<<"address of gih obj into method isRespected: "<<this->gih<<endl;
        the_link=this->gih->getTheLinkByNodes(
                    this->gih->getNodeByText(firstNodeName),
                    this->gih->getNodeByText(secondNodeName)
                    );
        if(!the_link)
            allConnected=false;
        else
        {
            //cout<<"distance of link is: "<<the_link->distance()<<endl;
            if(the_link->distance()==INT_MAX || the_link->distance()==0)
                allConnected=false;
            Q_ASSERT_X(the_link->fromNode()==this->gih->getNodeByText(firstNodeName), "all connected::is respected", QString("lolwut? from node: %1").arg(firstNodeName).toStdString().c_str());
            Q_ASSERT_X(the_link->toNode()==this->gih->getNodeByText(secondNodeName), "all connected::is respected", QString("lolwut? to node %1").arg(secondNodeName).toStdString().c_str());
        }
    }
    //return false;
    return allConnected;
}

bool AllConnectedToEachOther::isEqualTo(Constraint *comparingConstraint)
{
    return false;
}


bool AllConnectedToEachOther::needsGIH()
{
    return true;
}


unsigned int AllConnectedToEachOther::calculateSolutionScore(Path candidate)
{
    unsigned int firstNode, secondNode;
    QString firstNodeName, secondNodeName;
    Link* the_link=NULL;
    unsigned int connections=0;
    bool allConnected=true;
    int candidateNodeNum=candidate.getPath().size();
    for(int index=0; index<candidateNodeNum-1; index++)
    {
        firstNode=candidate.getPath().at(index);
        secondNode=candidate.getPath().at(index+1);
        //cout<<"firstNode is:"<<firstNode<<"\t"<<"secondNode is:"<<secondNode<<endl;
        firstNodeName=candidate.getNameByPoint(firstNode);
        secondNodeName=candidate.getNameByPoint(secondNode);
        //cout<<"firstNodeName is:"<<firstNodeName.toStdString()<<endl;
        //cout<<"secondNodeName is:"<<secondNodeName.toStdString()<<endl;
        //cout<<"address of gih obj into method isRespected: "<<this->gih<<endl;
        the_link=this->gih->getTheLinkByNodes(
                    this->gih->getNodeByText(firstNodeName),
                    this->gih->getNodeByText(secondNodeName)
                    );
        if(!the_link)
            allConnected=false;
        else
        {

            //cout<<"distance of link is: "<<the_link->distance()<<endl;
            if(!(the_link->distance()==INT_MAX || the_link->distance()==0))
                connections++;

            Q_ASSERT_X(the_link->fromNode()==this->gih->getNodeByText(firstNodeName), "all connected -> is respected", "lolwut?");
            Q_ASSERT_X(the_link->toNode()==this->gih->getNodeByText(secondNodeName), "all connected -> is respected", "lolwut?");
            //if(allConnected)
            //    connections++;
        }
    }
    //in order to get full score (N=#nodes in solution)
    if(connections==candidateNodeNum-1)
        connections++;
    return connections;
}
