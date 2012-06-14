#ifndef SOLUTIONTESTINGDIALOG_H
#define SOLUTIONTESTINGDIALOG_H

#include <QDialog>
#include "graphinformationhandler.h"
#include <QListWidgetItem>

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

    Path generatePathFromString(QString givenPath);

private slots:
    void on_addSolutionPushButton_clicked();
    void on_helpPushButton_clicked();
    void on_solutionListWidget_itemClicked(QListWidgetItem* item);

};

#endif // SOLUTIONTESTINGDIALOG_H
