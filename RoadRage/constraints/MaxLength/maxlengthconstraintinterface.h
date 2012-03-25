#ifndef MAXLENGTHCONSTRAINTINTERFACE_H
#define MAXLENGTHCONSTRAINTINTERFACE_H

#include "constraintdialog.h"
#include "constraintinterface.h"
#include "constraints/MaxLength/maxlengthconstraint.h"
#include "constraints/MaxLength/maxlengthconstraintdialog.h"

class MaxLengthConstraintInterface : public ConstraintInterface
{
public:
    MaxLengthConstraintInterface(GraphInformationHandler *gih);

    MaxLengthConstraint* getConstraintObj();
    ConstraintDialog* getDialog();
    bool hasUI();
};

#endif // MAXLENGTHCONSTRAINTINTERFACE_H
