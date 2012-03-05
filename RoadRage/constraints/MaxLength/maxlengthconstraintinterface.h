#ifndef MAXLENGTHCONSTRAINTINTERFACE_H
#define MAXLENGTHCONSTRAINTINTERFACE_H

#include "constraintinterface.h"
#include "constraints/MaxLength/maxlengthconstraint.h"
#include "constraints/MaxLength/maxlengthconstraintdialog.h"

class MaxLengthConstraintInterface : public ConstraintInterface
{
public:
    MaxLengthConstraintInterface(GraphInformationHandler *gih);

    MaxLengthConstraint* getConstraintObj();
    QDialog* getDialog();
    bool hasUI();
};

#endif // MAXLENGTHCONSTRAINTINTERFACE_H
