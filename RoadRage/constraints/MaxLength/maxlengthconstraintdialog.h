#ifndef MAXLENGTHCONSTRAINTDIALOG_H
#define MAXLENGTHCONSTRAINTDIALOG_H

#include "constraintdialog.h"
#include "graphinformationhandler.h"
#include "constraints/MaxLength/maxlengthconstraint.h"

namespace Ui {
class MaxLengthConstraintDialog;
}

class MaxLengthConstraintDialog : public ConstraintDialog
{
    Q_OBJECT
    
public:
    explicit MaxLengthConstraintDialog(
            GraphInformationHandler *gih,
            QWidget *parent = 0);
    ~MaxLengthConstraintDialog();

    //MaxLengthConstraint *getConstraintObj();
    Constraint* getConstraintObj();
    
private:
    Ui::MaxLengthConstraintDialog *ui;
    GraphInformationHandler *gih;
    MaxLengthConstraint *constraintObj;

private slots:
    void buttonBoxAcceptedSlot();
};

#endif // MAXLENGTHCONSTRAINTDIALOG_H
