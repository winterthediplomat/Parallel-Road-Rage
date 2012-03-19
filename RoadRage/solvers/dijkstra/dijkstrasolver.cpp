#include "dijkstrasolver.h"

DijkstraSolver::DijkstraSolver()
    :Solver()
{
}



void
DijkstraSolver::getSolutions(QString startNode, QString endNode,
                             Path &fasterPath, unsigned int &distanceOfPath)
{

    //startNodeNum (IN): int, the number of the start node
    //endNodeNum (IN): int, the number of the end node
    //fasterPath (OUT): Path, the path that lets you arrive at endNode from startNode
    //distance : QVector<int>, it will contain distances of all nodes in the graph
    //previous : QVector<int>, it will contain previous nodes of all nodes in the graph
    //visited : QVector<bool>, it will contain "visited" flag of related node


    //initializing Dijkstra calculation
    const unsigned int NODE_NO=this->gih->getNodes().size();
    unsigned int startNodeNum, endNodeNum;
    for(unsigned int index=0; index<NODE_NO; index++)
    {
        if(this->gih->getNodeByIndex(index)==this->gih->getNodeByText(startNode))
            startNodeNum=index;
        if(this->gih->getNodeByIndex(index)==this->gih->getNodeByText(endNode))
            endNodeNum=index;
    }
    unsigned int matrix[NODE_NO][NODE_NO];
    //unsigned int INFINITO=2147483647;
    unsigned int INFINITO=INT_MAX;
    QVector<bool> visited;
    QVector<int> distance;
    QVector<int> previous;
    //carico la matrice
    for(unsigned int i=0; i<NODE_NO; i++)
    {
        for(unsigned int j=0; j<NODE_NO; j++)
        {
            Link* link=this->gih->getTheLinkByNodes(this->gih->getNodeByIndex(i), this->gih->getNodeByIndex(j));
            if(link && link->distance()!=0 && link->distance()!=INFINITO)
            {
                matrix[i][j]=link->distance();
            }
            else
            {
                matrix[i][j]=INFINITO;
            }
        }
        visited.append(false);
        previous.append(-1);
        distance.append(INFINITO);
    }
    //cout<<"startNodeNum=="<<startNodeNum<<"\tendNodeNum=="<<endNodeNum<<endl;
    //cout<<"caricata la matrice!"<<endl;

    //starting work
    distance[startNodeNum]=0;
    unsigned int min_length, actualNodeNum;
    bool arrivedAtEnd=false;
    while(!arrivedAtEnd)
    {
        min_length=INFINITO;
        for(unsigned int candidateNodeNum=0; candidateNodeNum<NODE_NO; candidateNodeNum++)
        {
            if(!visited[candidateNodeNum] && distance[candidateNodeNum]<=min_length)
            {
                actualNodeNum=candidateNodeNum;
                min_length=distance[actualNodeNum];
            }
        }
        visited[actualNodeNum]=true;
        if ((min_length==INFINITO) || (actualNodeNum==endNodeNum))
        {
            arrivedAtEnd=true;
        }
        else
        {
            for(unsigned int i=0; i<NODE_NO; i++)
            {
                if(matrix[actualNodeNum][i] && distance[i]>distance[actualNodeNum]+matrix[actualNodeNum][i])
                {
                    distance[i]=distance[actualNodeNum]+matrix[actualNodeNum][i];
                    previous[i]=actualNodeNum;
                }
            }
        }
    } //end while

    //end of Dijkstra calculation, now go to retrieve path
    fasterPath.appendPoint(startNodeNum);
    for(unsigned int prevIndex=endNodeNum;
        previous[prevIndex]!=startNodeNum && previous[prevIndex]!=-1; prevIndex=previous[prevIndex])
    {
        fasterPath.appendPoint(prevIndex, true);
    }
    distanceOfPath=distance[endNodeNum];
}

void
DijkstraSolver::setGIH(GraphInformationHandler* gih)
{
    this->gih=gih;
}
