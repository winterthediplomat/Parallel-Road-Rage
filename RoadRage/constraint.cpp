//#include "StdAfx.h"
#include "constraint.h"
#include "iostream"
using namespace std;

Constraint::Constraint()
{
}

bool Constraint::isRespected(Path candidate)
{
    return false;
}

bool Constraint::isEqualTo(Constraint *comparingConstraint)
{
    return false;
}

void Constraint::printName()
{
    cout<<"Constraint!"<<endl;
}

QString Constraint::generateJSON()
{
    return QString("");
}

/*
bool Constraint::needsGIH()
{
    return false;
}
*/
void Constraint::setGIH(GraphInformationHandler *gih)
{
    /*
      questo metodo funziona per magia.
      non toccare assolutamente.
    */
    this->gih=gih;
    cout<<"saved address of gih is: "<<this->gih<<endl;
    cout<<"no lolnode :yaoming:"<<endl;
}
