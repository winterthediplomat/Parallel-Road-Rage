//#include "StdAfx.h"
#include <iostream>
#include "solver.h"
using namespace std;

Solver::Solver()
{
    this->acceptConstraints=new QVector<Constraint*>;
    this->rejectConstraints=new QVector<Constraint*>;
}

/*
void Solver::getSolutions(Path startSolution, QVector<Path> *solutions)
{
    QMessage::critical(this, "D:", "D:");
}
*/

bool Solver::rejectSolution(Path candidate)
{
    bool isRejected=false;
//#pragma omp parallel for
    for(int i=0; i<this->rejectConstraints->size(); i++)
    {
        //this->rejectConstraints->at(i)->printName();
        if(!this->rejectConstraints->at(i)->isRespected(candidate))
        {
            //cout<<"not respected constraint at "<<i<<"th position!"<<endl;
            isRejected=true;
        }
    }
    return isRejected;
}

bool Solver::acceptSolution(Path candidate)
{
    bool isAccepted=false;
    //bool isAccepted=true;
    //unsigned int isAccepted=1;
//#pragma omp parallel for
    for(int i=0; i<this->acceptConstraints->size(); i++)
    {
        //if(this->acceptConstraints->at(i)->isRespected(candidate))
        //if(this->acceptConstraints->at(i)->isRespected(candidate)==false)
            isAccepted=true;
            //isAccepted=false;
            //isAccepted*=0;
    }
    return isAccepted;
    //return isAccepted==1?true:false;
}

void Solver::addAcceptConstraint(Constraint *newConstraint)
{this->acceptConstraints->push_back(newConstraint);}

void Solver::addRejectConstraint(Constraint *newConstraint)
{this->rejectConstraints->push_back(newConstraint);}
