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
      (
       LOL, semplicemente un errore riguardante
       la gestione di un puntatore nella sottoclasse.
       il commento perà è decisamente LOLloso, così ho deciso di lasciarlo.
      )
    */
    this->gih=gih;
    cout<<"saved address of gih is: "<<this->gih<<endl;
    cout<<"no lolnode :yaoming:"<<endl;
}

//needed by GeneticEngine, and Constraint is the only one
//that can give this info.
unsigned int Constraint::calculateSolutionScore(Path candidate)
{
    /*
      questo metodo serve a dire quanto è corretta una soluzione (candidate).
      se si deve verificare solo una condizione
      (e.g. la soluzione comincia con un certo valore)
      si deve comportare in questo modo:
         isRespected(candidate)?N:0
      dove N è la lunghezza della soluzione.

      se si deve verificare un vincolo più articolato
      (e.g. se tutti gli elementi sono differenti)
      si deve dare un valore nell'intervallo (0; N)
      a seconda di quanto la soluzione sia corretta
      (e.g 1321 --> 3, 1111 --> 1, 1234 --> 4=N )
    */
    cout<<":yaoming: on Constraint::calculateSolutionScore(Path)"<<endl;
    return INT_MAX;
}
