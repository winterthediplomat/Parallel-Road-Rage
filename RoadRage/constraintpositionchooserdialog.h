#ifndef CONSTRAINTPOSITIONCHOOSERDIALOG_H
#define CONSTRAINTPOSITIONCHOOSERDIALOG_H

#include <QDialog>

namespace Ui {
class ConstraintPositionChooserDialog;
}

class ConstraintPositionChooserDialog : public QDialog
{
    Q_OBJECT
    
public:
    bool isAccept;
    explicit ConstraintPositionChooserDialog(QWidget *parent = 0);
    ~ConstraintPositionChooserDialog();
    
private:
    Ui::ConstraintPositionChooserDialog *ui;
private slots:
    void setAccepted();
};

#endif // CONSTRAINTPOSITIONCHOOSERDIALOG_H
