/********************************************************************************
** Form generated from reading UI file 'maxlengthconstraintdialog.ui'
**
** Created: Thu 12. Jan 18:18:16 2012
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAXLENGTHCONSTRAINTDIALOG_H
#define UI_MAXLENGTHCONSTRAINTDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_MaxLengthConstraintDialog
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QSpinBox *spinBox;

    void setupUi(QDialog *MaxLengthConstraintDialog)
    {
        if (MaxLengthConstraintDialog->objectName().isEmpty())
            MaxLengthConstraintDialog->setObjectName(QString::fromUtf8("MaxLengthConstraintDialog"));
        MaxLengthConstraintDialog->resize(383, 176);
        buttonBox = new QDialogButtonBox(MaxLengthConstraintDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(30, 130, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(MaxLengthConstraintDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 20, 371, 41));
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        spinBox = new QSpinBox(MaxLengthConstraintDialog);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(140, 70, 91, 41));
        QFont font1;
        font1.setPointSize(13);
        spinBox->setFont(font1);
        spinBox->setMinimum(0);

        retranslateUi(MaxLengthConstraintDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), MaxLengthConstraintDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), MaxLengthConstraintDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(MaxLengthConstraintDialog);
    } // setupUi

    void retranslateUi(QDialog *MaxLengthConstraintDialog)
    {
        MaxLengthConstraintDialog->setWindowTitle(QApplication::translate("MaxLengthConstraintDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MaxLengthConstraintDialog", "How much your solution will be long?", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MaxLengthConstraintDialog: public Ui_MaxLengthConstraintDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAXLENGTHCONSTRAINTDIALOG_H
