/********************************************************************************
** Form generated from reading UI file 'constraintchooserdialog.ui'
**
** Created: Wed 21. Mar 12:18:32 2012
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONSTRAINTCHOOSERDIALOG_H
#define UI_CONSTRAINTCHOOSERDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHeaderView>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ConstraintChooserDialog
{
public:
    QDialogButtonBox *buttonBox;
    QListWidget *setupConstraintsListWidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *createPushButton;
    QRadioButton *acceptRadioButton;
    QRadioButton *rejectRadioButton;
    QPushButton *updatePushButton;
    QPushButton *deletePushButton;
    QListWidget *constraintsListWidget;

    void setupUi(QDialog *ConstraintChooserDialog)
    {
        if (ConstraintChooserDialog->objectName().isEmpty())
            ConstraintChooserDialog->setObjectName(QString::fromUtf8("ConstraintChooserDialog"));
        ConstraintChooserDialog->resize(618, 351);
        buttonBox = new QDialogButtonBox(ConstraintChooserDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(250, 310, 329, 23));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        setupConstraintsListWidget = new QListWidget(ConstraintChooserDialog);
        setupConstraintsListWidget->setObjectName(QString::fromUtf8("setupConstraintsListWidget"));
        setupConstraintsListWidget->setGeometry(QRect(370, 30, 211, 261));
        verticalLayoutWidget = new QWidget(ConstraintChooserDialog);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(239, 70, 121, 162));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        createPushButton = new QPushButton(verticalLayoutWidget);
        createPushButton->setObjectName(QString::fromUtf8("createPushButton"));

        verticalLayout->addWidget(createPushButton);

        acceptRadioButton = new QRadioButton(verticalLayoutWidget);
        acceptRadioButton->setObjectName(QString::fromUtf8("acceptRadioButton"));

        verticalLayout->addWidget(acceptRadioButton);

        rejectRadioButton = new QRadioButton(verticalLayoutWidget);
        rejectRadioButton->setObjectName(QString::fromUtf8("rejectRadioButton"));

        verticalLayout->addWidget(rejectRadioButton);

        updatePushButton = new QPushButton(verticalLayoutWidget);
        updatePushButton->setObjectName(QString::fromUtf8("updatePushButton"));

        verticalLayout->addWidget(updatePushButton);

        deletePushButton = new QPushButton(verticalLayoutWidget);
        deletePushButton->setObjectName(QString::fromUtf8("deletePushButton"));

        verticalLayout->addWidget(deletePushButton);

        constraintsListWidget = new QListWidget(ConstraintChooserDialog);
        constraintsListWidget->setObjectName(QString::fromUtf8("constraintsListWidget"));
        constraintsListWidget->setGeometry(QRect(20, 20, 211, 261));

        retranslateUi(ConstraintChooserDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), ConstraintChooserDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ConstraintChooserDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(ConstraintChooserDialog);
    } // setupUi

    void retranslateUi(QDialog *ConstraintChooserDialog)
    {
        ConstraintChooserDialog->setWindowTitle(QApplication::translate("ConstraintChooserDialog", "Constraint Chooser Dialog", 0, QApplication::UnicodeUTF8));
        createPushButton->setText(QApplication::translate("ConstraintChooserDialog", "Create\n"
"constraint", 0, QApplication::UnicodeUTF8));
        acceptRadioButton->setText(QApplication::translate("ConstraintChooserDialog", "Accept constraint", 0, QApplication::UnicodeUTF8));
        rejectRadioButton->setText(QApplication::translate("ConstraintChooserDialog", "Reject constraint", 0, QApplication::UnicodeUTF8));
        updatePushButton->setText(QApplication::translate("ConstraintChooserDialog", "Update\n"
"constraint", 0, QApplication::UnicodeUTF8));
        deletePushButton->setText(QApplication::translate("ConstraintChooserDialog", "Delete\n"
"constraint", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ConstraintChooserDialog: public Ui_ConstraintChooserDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONSTRAINTCHOOSERDIALOG_H
