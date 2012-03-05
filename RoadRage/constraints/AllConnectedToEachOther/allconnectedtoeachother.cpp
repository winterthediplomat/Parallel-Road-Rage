//#include "allconnectedtoeachother.h"
#include "constraints/AllConnectedToEachOther/allconnectedtoeachother.h"
#include <QtGlobal>
#include "iostream"
#include "link.h"
using namespace std;

AllConnectedToEachOther::AllConnectedToEachOther()
{
    cout<<"address of AllConnectedToEachOther: "<<this<<endl;
}

void AllConnectedToEachOther::setGIH(GraphInformationHandler *gih)
{
    //cout<<gih<<endl;
    this->gih=gih;
    cout<<"saved address of gih is:"<<this->gih<<endl;
    Node *lol=this->gih->getNodeByText("Node 1");
    cout<<"lolnode has address: "<<lol<<endl;
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
    if(&candidate==0)
        return false;
    if(candidate.getPath().size()<2)
        return true;

    unsigned int firstNode, secondNode;
    QString firstNodeName, secondNodeName;
    Link* the_link=NULL;
    bool allConnected=true;
    int candidateNodeNum=candidate.getPath().size();
    //the risk is possible...
    //Q_ASSERT_X(this->gih!=0 && this->gih!=0xbaadf00d, "AllConnected::isRespected", "saved gih obj is not right (maybe corrupted?)");
    for(int index=0; index<candidateNodeNum-1; index++)
    {
        firstNode=candidate.getPath().at(index);
        secondNode=candidate.getPath().at(index+1);
        cout<<"firstNode is:"<<firstNode<<"\t"<<"secondNode is:"<<secondNode<<endl;
        firstNodeName=candidate.getNameByPoint(firstNode);
        secondNodeName=candidate.getNameByPoint(secondNode);
        cout<<"firstNodeName is:"<<firstNodeName.toStdString()<<endl;
        cout<<"secondNodeName is:"<<secondNodeName.toStdString()<<endl;
        cout<<"address of gih obj into method isRespected: "<<this->gih<<endl;
        the_link=this->gih->getTheLinkByNodes(
                    this->gih->getNodeByText(firstNodeName),
                    this->gih->getNodeByText(secondNodeName)
                    );
        if(!the_link)
            allConnected=false;
        else
        {
            cout<<"distance of link is: "<<the_link->distance()<<endl;
            if(the_link->distance()==INT_MAX || the_link->distance()==0)
                allConnected=false;
            Q_ASSERT_X(the_link->fromNode()==this->gih->getNodeByText(firstNodeName), "all connected -> is respected", "lolwut?");
            Q_ASSERT_X(the_link->toNode()==this->gih->getNodeByText(secondNodeName), "all connected -> is respected", "lolwut?");
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
