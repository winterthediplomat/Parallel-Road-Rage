/********************************************************************************
** Form generated from reading UI file 'nodesselectordialog.ui'
**
** Created: Wed 8. Jun 17:50:58 2011
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NODESSELECTORDIALOG_H
#define UI_NODESSELECTORDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QListWidget>

QT_BEGIN_NAMESPACE

class Ui_NodesSelectorDialog
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *distanceLabel;
    QLabel *linkLabel;
    QListWidget *firstNodeListWidget;
    QListWidget *secondNodeListWidget;
    QCheckBox *switchCheckBox;

    void setupUi(QDialog *NodesSelectorDialog)
    {
        if (NodesSelectorDialog->objectName().isEmpty())
            NodesSelectorDialog->setObjectName(QString::fromUtf8("NodesSelectorDialog"));
        NodesSelectorDialog->resize(400, 300);
        buttonBox = new QDialogButtonBox(NodesSelectorDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(30, 250, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        distanceLabel = new QLabel(NodesSelectorDialog);
        distanceLabel->setObjectName(QString::fromUtf8("distanceLabel"));
        distanceLabel->setEnabled(true);
        distanceLabel->setGeometry(QRect(30, 120, 311, 41));
        QFont font;
        font.setPointSize(10);
        distanceLabel->setFont(font);
        linkLabel = new QLabel(NodesSelectorDialog);
        linkLabel->setObjectName(QString::fromUtf8("linkLabel"));
        linkLabel->setEnabled(true);
        linkLabel->setGeometry(QRect(30, 160, 311, 41));
        linkLabel->setFont(font);
        firstNodeListWidget = new QListWidget(NodesSelectorDialog);
        firstNodeListWidget->setObjectName(QString::fromUtf8("firstNodeListWidget"));
        firstNodeListWidget->setGeometry(QRect(30, 10, 141, 91));
        secondNodeListWidget = new QListWidget(NodesSelectorDialog);
        secondNodeListWidget->setObjectName(QString::fromUtf8("secondNodeListWidget"));
        secondNodeListWidget->setGeometry(QRect(210, 10, 141, 91));
        switchCheckBox = new QCheckBox(NodesSelectorDialog);
        switchCheckBox->setObjectName(QString::fromUtf8("switchCheckBox"));
        switchCheckBox->setGeometry(QRect(120, 200, 121, 31));
        switchCheckBox->setFont(font);
        switchCheckBox->setChecked(false);

        retranslateUi(NodesSelectorDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), NodesSelectorDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), NodesSelectorDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(NodesSelectorDialog);
    } // setupUi

    void retranslateUi(QDialog *NodesSelectorDialog)
    {
        NodesSelectorDialog->setWindowTitle(QApplication::translate("NodesSelectorDialog", "Select Nodes", 0, QApplication::UnicodeUTF8));
        distanceLabel->setText(QApplication::translate("NodesSelectorDialog", "the distance between nodes is: ", 0, QApplication::UnicodeUTF8));
        linkLabel->setText(QApplication::translate("NodesSelectorDialog", "a link between nodes", 0, QApplication::UnicodeUTF8));
        switchCheckBox->setText(QApplication::translate("NodesSelectorDialog", "Switch nodes", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class NodesSelectorDialog: public Ui_NodesSelectorDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NODESSELECTORDIALOG_H
