#ifndef LINKINFODIALOG_H
#define LINKINFODIALOG_H

#include <QDialog>
#include "graphinformationhandler.h"
#include "node.h"
#include "link.h"

namespace Ui {
    class LinkInfoDialog;
}

class LinkInfoDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LinkInfoDialog(QWidget *parent = 0);
    LinkInfoDialog(Node *firstSelected=NULL, Node *secondSelected=NULL,
                   QWidget *parent=0);
    ~LinkInfoDialog();

    Node *getFirst();
    Node *getSecond();
    Link *getFirstToSecondLink();
    Link *getsecondToFirstLink();
    QList<Link* > links();


private:
    Ui::LinkInfoDialog *ui;
    Node *first;
    Node *second;
    Link *firstToSecond;
    Link *secondToFirst;
    bool isFirstLinkAvailable;
    bool isSecondLinkAvaiable;
    GraphInformationHandler* gih;

private slots:
    void setEnabledFirst();
    void setEnabledSecond();
    void updateFirstLinkDistance();
    void updateSecondLinkDistance();
};

#endif // LINKINFODIALOG_H
