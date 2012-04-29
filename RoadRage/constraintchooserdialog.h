#ifndef CONSTRAINTCHOOSERDIALOG_H
#define CONSTRAINTCHOOSERDIALOG_H

#include <QDialog>
//#include <QStringList>
#include "graphinformationhandler.h"

namespace Ui {
class ConstraintChooserDialog;
}

class ConstraintChooserDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit ConstraintChooserDialog(GraphInformationHandler *gih,
                                     QWidget *parent = 0);
    ~ConstraintChooserDialog();
    
private:
    Ui::ConstraintChooserDialog *ui;
    GraphInformationHandler *gih;
    int currentConstraintListWidgetRow;
    int currentSetUpConstraintListWidgetRow;

    void loadSavedConstraints();
    bool isAcceptConstraint();

private slots:
    void currentRowChangedInConstraintListWidget(int currentRow);
    void currentRowChangedInSetUpConstraintListWidget(int currentRow);
    void createConstraintSlot();
    void deleteConstraintSlot();
    void updateConstraintSlot();
};

#endif // CONSTRAINTCHOOSERDIALOG_H
