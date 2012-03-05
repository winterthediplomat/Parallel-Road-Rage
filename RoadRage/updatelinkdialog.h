#ifndef UPDATELINKDIALOG_H
#define UPDATELINKDIALOG_H

#include <QDialog>
#include "graphinformationhandler.h"
#include "node.h"
#include "link.h"

namespace Ui {
    class UpdateLinkDialog;
}

class UpdateLinkDialog : public QDialog
{
    Q_OBJECT

public:
    explicit UpdateLinkDialog(QWidget *parent = 0);
    UpdateLinkDialog(unsigned int first, unsigned int second, QString firstText, QString secondText, QWidget *parent=0);
    ~UpdateLinkDialog();

    unsigned int getFirst();
    unsigned int getSecond();
    QList<unsigned int> links();


private:
    Ui::UpdateLinkDialog *ui;
    unsigned int firstDistance;
    unsigned int secondDistance;
    bool isFirstLinkAvailable;
    bool isSecondLinkAvaiable;

private slots:
    void setEnabledFirst();
    void setEnabledSecond();
    void updateFirstLinkDistance();
    void updateSecondLinkDistance();

};

#endif // UPDATELINKDIALOG_H
