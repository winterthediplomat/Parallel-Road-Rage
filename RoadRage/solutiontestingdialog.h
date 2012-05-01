#ifndef SOLUTIONTESTINGDIALOG_H
#define SOLUTIONTESTINGDIALOG_H

#include <QDialog>
#include "graphinformationhandler.h"

namespace Ui {
class SolutionTestingDialog;
}

class SolutionTestingDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit SolutionTestingDialog(QWidget *parent = 0);
    ~SolutionTestingDialog();

    void setGIH(GraphInformationHandler *gih);
    void scoreCalculation(bool isScore=false);
    
private:
    Ui::SolutionTestingDialog *ui;
    GraphInformationHandler *gih;
    bool isScoreCalculation;

private slots:
    void on_addSolutionPushButton_clicked();
    void on_helpPushButton_clicked();
};

#endif // SOLUTIONTESTINGDIALOG_H
