#ifndef MAXLENGTHCONSTRAINTDIALOG_H
#define MAXLENGTHCONSTRAINTDIALOG_H

#include <QDialog>
#include "graphinformationhandler.h"
#include "constraints/MaxLength/maxlengthconstraint.h"

namespace Ui {
class MaxLengthConstraintDialog;
}

class MaxLengthConstraintDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit MaxLengthConstraintDialog(
            GraphInformationHandler *gih,
            QWidget *parent = 0);
    ~MaxLengthConstraintDialog();
    
private:
    Ui::MaxLengthConstraintDialog *ui;
    GraphInformationHandler *gih;

private slots:
    void buttonBoxAcceptedSlot();
};

#endif // MAXLENGTHCONSTRAINTDIALOG_H
