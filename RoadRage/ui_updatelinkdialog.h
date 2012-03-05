/********************************************************************************
** Form generated from reading UI file 'updatelinkdialog.ui'
**
** Created: Thu 2. Jun 23:22:01 2011
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UPDATELINKDIALOG_H
#define UI_UPDATELINKDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_UpdateLinkDialog
{
public:
    QDialogButtonBox *buttonBox;
    QPushButton *firstEnableLinkButton;
    QPushButton *secondEnableLinkButton;
    QSpinBox *firstDistanceSpinBox;
    QSpinBox *secondDistanceSpinBox;
    QLabel *firstFromNodeLabel;
    QLabel *firstToNodeLabel;
    QLabel *secondFromNodeLabel;
    QLabel *secondToNodeLabel;

    void setupUi(QDialog *UpdateLinkDialog)
    {
        if (UpdateLinkDialog->objectName().isEmpty())
            UpdateLinkDialog->setObjectName(QString::fromUtf8("UpdateLinkDialog"));
        UpdateLinkDialog->setWindowModality(Qt::ApplicationModal);
        UpdateLinkDialog->resize(400, 300);
        buttonBox = new QDialogButtonBox(UpdateLinkDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        firstEnableLinkButton = new QPushButton(UpdateLinkDialog);
        firstEnableLinkButton->setObjectName(QString::fromUtf8("firstEnableLinkButton"));
        firstEnableLinkButton->setGeometry(QRect(300, 40, 91, 51));
        secondEnableLinkButton = new QPushButton(UpdateLinkDialog);
        secondEnableLinkButton->setObjectName(QString::fromUtf8("secondEnableLinkButton"));
        secondEnableLinkButton->setGeometry(QRect(300, 110, 91, 51));
        firstDistanceSpinBox = new QSpinBox(UpdateLinkDialog);
        firstDistanceSpinBox->setObjectName(QString::fromUtf8("firstDistanceSpinBox"));
        firstDistanceSpinBox->setGeometry(QRect(210, 50, 81, 31));
        secondDistanceSpinBox = new QSpinBox(UpdateLinkDialog);
        secondDistanceSpinBox->setObjectName(QString::fromUtf8("secondDistanceSpinBox"));
        secondDistanceSpinBox->setGeometry(QRect(210, 120, 81, 31));
        firstFromNodeLabel = new QLabel(UpdateLinkDialog);
        firstFromNodeLabel->setObjectName(QString::fromUtf8("firstFromNodeLabel"));
        firstFromNodeLabel->setGeometry(QRect(20, 60, 58, 17));
        firstToNodeLabel = new QLabel(UpdateLinkDialog);
        firstToNodeLabel->setObjectName(QString::fromUtf8("firstToNodeLabel"));
        firstToNodeLabel->setGeometry(QRect(120, 60, 58, 17));
        secondFromNodeLabel = new QLabel(UpdateLinkDialog);
        secondFromNodeLabel->setObjectName(QString::fromUtf8("secondFromNodeLabel"));
        secondFromNodeLabel->setGeometry(QRect(20, 130, 58, 17));
        secondToNodeLabel = new QLabel(UpdateLinkDialog);
        secondToNodeLabel->setObjectName(QString::fromUtf8("secondToNodeLabel"));
        secondToNodeLabel->setGeometry(QRect(120, 130, 58, 17));

        retranslateUi(UpdateLinkDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), UpdateLinkDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), UpdateLinkDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(UpdateLinkDialog);
    } // setupUi

    void retranslateUi(QDialog *UpdateLinkDialog)
    {
        UpdateLinkDialog->setWindowTitle(QApplication::translate("UpdateLinkDialog", "Update Links", 0, QApplication::UnicodeUTF8));
        firstEnableLinkButton->setText(QApplication::translate("UpdateLinkDialog", "Disable\n"
"Link", 0, QApplication::UnicodeUTF8));
        secondEnableLinkButton->setText(QApplication::translate("UpdateLinkDialog", "Disable\n"
"Link", 0, QApplication::UnicodeUTF8));
        firstFromNodeLabel->setText(QApplication::translate("UpdateLinkDialog", "TextLabel", 0, QApplication::UnicodeUTF8));
        firstToNodeLabel->setText(QApplication::translate("UpdateLinkDialog", "TextLabel", 0, QApplication::UnicodeUTF8));
        secondFromNodeLabel->setText(QApplication::translate("UpdateLinkDialog", "TextLabel", 0, QApplication::UnicodeUTF8));
        secondToNodeLabel->setText(QApplication::translate("UpdateLinkDialog", "TextLabel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class UpdateLinkDialog: public Ui_UpdateLinkDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UPDATELINKDIALOG_H
