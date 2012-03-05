#ifndef CONSTRAINTS_H
#define CONSTRAINTS_H

#include "QVector"
#include "QList"
#include "QAction"
#include "constraintinterface.h"

#include "constraints/AllDifferentElements/alldifferentelementsinterface.h"

/*
(author:alfateam123; date:6/12/2011 dd/mm/yyyy;
state:disgustato dal bruttissimo cheat.)
ciao, sono lo sviluppatore di questo progetto, che si chiama
PRR e, no, non è una pernacchia, ma Parallel Road Rage. Non sono
qui per spiegarti a cosa serve, perchè lo sviluppo o altre menate di
questo tipo.
quello che voglio ricordarti è, prima di cominciare a sviluppare un
qualunque software, *devi* studiarne i requisiti e quindi *progettarlo*,
magari secondo i principi che puoi imparare attraverso il "Head First Design Patterns"
(che BTW è un ottimo libro). **solo dopo** tutto ciò puoi pensare di
cominciare a svilupparlo.
questo file è una soluzione semplicistica ad una mancanza di studio
dell'applicazione dalla quale deriva. Impara dai tuoi errori e da quelli degli altri,
soprattutto se così evidenti.

yeah, this is the gold hammer!
*/
/*
enum ConstraintApplicationField
{

};

enum ConstraintsEnum
{

    ALL_DIFFERENT_ELEMENTS=0,
};
*/

/*
QVector<ConstraintInterface*> constrInterfaces=
{
    new AllDifferentElementsInterface(),
};
*/

/*
QVector<ConstraintInterface*> *constrInterfaces=
        new QVector<ConstraintInterface*>;
constrInterfaces->append(new ConstraintInterface());
*/
/*
  this function returns a Constraint*, based on the ConstraintEnum
  we want back.

  if you want Constraint SimpleConstraint you should call
  //before
  Constraint* constr=provideConstraint(SIMPLE_CONSTRAINT);
  //after
*/
Constraint* provideConstraintObj(int constraintIndex)
{
    return constrInterfaces[constraintIndex]->getConstraintObj();
}

QDialog* provideConstraintDialog(int constraintIndex)
{
    if(constrInterfaces[constraintIndex]->hasUI())
        return constrInterfaces[constraintIndex]->getDialog();
    else
        return 0; //NULL is too mainstream ;D
}

QStringList constraintsNames()
{
    QStringList constraintNamesList;
    for(int i=0; i<constrInterfaces.size(); i++)
    {
        constraintNamesList.append(constrInterfaces[i]->name());
    }
    return constraintNamesList;
}

QList<QAction*> provideConstraintActions()
{
    QList<QAction*> constraintActions;
    for(int i=0; i<constrInterfaces.size(); i++)
    {
        constraintActions.append(constrInterfaces[i]->constraintAction());
    }
    return constraintActions;
}

#endif // CONSTRAINTS_H
