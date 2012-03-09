//#include "StdAfx.h"
#include "path.h"
#include <iostream>
using namespace std;
/*
Path::Path()
{
}*/

/*
void Path::nextCandidates(vector<Path> *nextCandidates)
{
    //this method *must* be overrided.
}*/

Path::Path(){}

Path::Path(unsigned int maxNodes)
{
    this->MAX_NODES=maxNodes;
}

Path::Path(unsigned int maxNodes, QVector<unsigned int> path)
{
    this->MAX_NODES=maxNodes;
    this->path=path;
}

QVector<unsigned int> Path::getPath()
{return path;}

void Path::appendPoint(unsigned int point)
{
    this->path.push_back(point);
}


/*
void Path::nextCandidates(QVector<Path> *nextCandidates)
{
    for(unsigned int i=0; i<this->MAX_NODES; i++)
    {
        //cout<<i<<endl;
        //vector<unsigned int> newPath=this->path;
        //newPath.push_back(i);
        //Path newsol(newPath);
        Path newsol(this->MAX_NODES, this->path);
        foreach(QString name, this->names)
            newsol.addName(name);
        newsol.appendPoint(i);
        nextCandidates->append(newsol);
    }
}
*/



int Path::getNodes()
{
    return this->MAX_NODES;
}


void Path::addName(QString name)
{
    this->names.push_back(name);
}

QVector<QString> Path::namesRelatedToPath()
{
    QVector<QString> namedPath;
	/*
    foreach(unsigned int point, this->path)
    {
        namedPath.append(this->getNameByPoint(point));
    }
	*/
	for(unsigned int i=0; i<this->path.size(); i++)
	{
		namedPath.push_back(this->getNameByPoint(this->path.at(i)));
	}
    return namedPath;
}


QString Path::getNameByPoint(unsigned int point)
{
    if(this->names.size()<point || point<0)
        return NULL;
    else
        return this->names.at(point);
}
