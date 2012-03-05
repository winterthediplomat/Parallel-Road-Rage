#ifndef NODESSELECTORDIALOG_H
#define NODESSELECTORDIALOG_H

#include <QDialog>
#include "graphinformationhandler.h"

namespace Ui {
    class NodesSelectorDialog;
}

class NodesSelectorDialog : public QDialog {
    Q_OBJECT
public:
    NodesSelectorDialog(GraphInformationHandler *gih, QWidget *parent = 0);
    ~NodesSelectorDialog();
    //methods that must be invoked after execution of dialog
    int getFirstNodeIndex();
    int getSecondNodeIndex();
    bool isSwitchNodesChecked();
    //methods that must be invoked before execution of dialog
    //invoked to set some UI things of the NodeSelectorDialog instance
    void setSwitchNodesChecked(bool state, bool isStateExchangeable=true);
    void setDistanceLabelVisible(bool isVisible=true);
    void setLinkExistingLabelVisible(bool isVisible=true);


protected:
    void changeEvent(QEvent *e);

private:
    void setupComboBoxes();

    Ui::NodesSelectorDialog *ui;
    GraphInformationHandler *gih;
    int firstIndex;
    int secondIndex;

private slots:
    void on_secondNodeListWidget_currentRowChanged(int currentRow);
    void on_firstNodeListWidget_currentRowChanged(int currentRow);
};

#endif // NODESSELECTORDIALOG_H
