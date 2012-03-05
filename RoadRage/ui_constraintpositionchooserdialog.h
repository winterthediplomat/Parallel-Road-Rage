/********************************************************************************
** Form generated from reading UI file 'constraintpositionchooserdialog.ui'
**
** Created: Wed 18. Jan 16:39:11 2012
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONSTRAINTPOSITIONCHOOSERDIALOG_H
#define UI_CONSTRAINTPOSITIONCHOOSERDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QRadioButton>

QT_BEGIN_NAMESPACE

class Ui_ConstraintPositionChooserDialog
{
public:
    QDialogButtonBox *buttonBox;
    QRadioButton *acceptRadioButton;
    QRadioButton *rejectRadioButton;
    QLabel *label;

    void setupUi(QDialog *ConstraintPositionChooserDialog)
    {
        if (ConstraintPositionChooserDialog->objectName().isEmpty())
            ConstraintPositionChooserDialog->setObjectName(QString::fromUtf8("ConstraintPositionChooserDialog"));
        ConstraintPositionChooserDialog->resize(302, 208);
        buttonBox = new QDialogButtonBox(ConstraintPositionChooserDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(-50, 160, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        acceptRadioButton = new QRadioButton(ConstraintPositionChooserDialog);
        acceptRadioButton->setObjectName(QString::fromUtf8("acceptRadioButton"));
        acceptRadioButton->setGeometry(QRect(80, 90, 151, 31));
        QFont font;
        font.setPointSize(11);
        acceptRadioButton->setFont(font);
        acceptRadioButton->setChecked(true);
        rejectRadioButton = new QRadioButton(ConstraintPositionChooserDialog);
        rejectRadioButton->setObjectName(QString::fromUtf8("rejectRadioButton"));
        rejectRadioButton->setGeometry(QRect(80, 120, 151, 31));
        rejectRadioButton->setFont(font);
        label = new QLabel(ConstraintPositionChooserDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 30, 231, 51));
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setWeight(75);
        label->setFont(font1);

        retranslateUi(ConstraintPositionChooserDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), ConstraintPositionChooserDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ConstraintPositionChooserDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(ConstraintPositionChooserDialog);
    } // setupUi

    void retranslateUi(QDialog *ConstraintPositionChooserDialog)
    {
        ConstraintPositionChooserDialog->setWindowTitle(QApplication::translate("ConstraintPositionChooserDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        acceptRadioButton->setText(QApplication::translate("ConstraintPositionChooserDialog", "Accept Constraint", 0, QApplication::UnicodeUTF8));
        rejectRadioButton->setText(QApplication::translate("ConstraintPositionChooserDialog", "Reject Constraint", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ConstraintPositionChooserDialog", "This is an accept\n"
" constraint or a reject one?", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ConstraintPositionChooserDialog: public Ui_ConstraintPositionChooserDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONSTRAINTPOSITIONCHOOSERDIALOG_H
