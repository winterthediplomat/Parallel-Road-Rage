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
    /*
      //original version: it's an EPIC FAIL
      //it just does not control about *ALL* the
      //constraint validation, but only ONE constraint.
      //It's just wondering: there is _at least one_ constraint
      //that says "this solution, in my opinion, is right" ?
    bool isAccepted=false;
    for(int i=0; i<this->acceptConstraints->size(); i++)
    {
        if(this->acceptConstraints->at(i)->isRespected(candidate))
            isAccepted=true;
    }
    return isAccepted;
    */
    unsigned int isAccepted=1;
    for(int i=0; i<this->acceptConstraints->size(); i++)
    {
        if(!this->acceptConstraints->at(i)->isRespected(candidate))
        {
            isAccepted*=0;
        }
    }
    return isAccepted==1;
}

void Solver::addAcceptConstraint(Constraint *newConstraint)
{this->acceptConstraints->push_back(newConstraint);}

void Solver::addRejectConstraint(Constraint *newConstraint)
{this->rejectConstraints->push_back(newConstraint);}
