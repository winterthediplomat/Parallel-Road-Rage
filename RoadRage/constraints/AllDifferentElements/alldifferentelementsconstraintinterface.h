#ifndef ALLDIFFERENTELEMENTSCONSTRAINTINTERFACE_H
#define ALLDIFFERENTELEMENTSCONSTRAINTINTERFACE_H

#include "constraintinterface.h"
#include "constraints/AllDifferentElements/alldifferentelementsconstraint.h"

class AllDifferentElementsConstraintInterface : public ConstraintInterface
{
public:
    AllDifferentElementsConstraintInterface(GraphInformationHandler *gih);

    AllDifferentElementsConstraint* getConstraintObj();
    //QDialog* getDialog();

    bool hasUI();
};

#endif // ALLDIFFERENTELEMENTSCONSTRAINTINTERFACE_H
