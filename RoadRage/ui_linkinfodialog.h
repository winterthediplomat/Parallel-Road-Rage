/********************************************************************************
** Form generated from reading UI file 'linkinfodialog.ui'
**
** Created: Sat 4. Jun 09:23:21 2011
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LINKINFODIALOG_H
#define UI_LINKINFODIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LinkInfoDialog
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QPushButton *secondEnableLinkButton;
    QSpinBox *firstDistanceSpinBox;
    QSpinBox *secondDistanceSpinBox;
    QLabel *firstToNodeLabel;
    QLabel *secondToNodeLabel;
    QLabel *secondFromNodeLabel;
    QLabel *label_4;
    QLabel *label_3;
    QLabel *firstFromNodeLabel;
    QLabel *firstFromNodeLabel_2;
    QPushButton *firstEnableLinkButton;
    QLabel *label;

    void setupUi(QDialog *LinkInfoDialog)
    {
        if (LinkInfoDialog->objectName().isEmpty())
            LinkInfoDialog->setObjectName(QString::fromUtf8("LinkInfoDialog"));
        LinkInfoDialog->setWindowModality(Qt::ApplicationModal);
        LinkInfoDialog->resize(441, 308);
        buttonBox = new QDialogButtonBox(LinkInfoDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(70, 270, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        gridLayoutWidget_2 = new QWidget(LinkInfoDialog);
        gridLayoutWidget_2->setObjectName(QString::fromUtf8("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(10, 30, 414, 220));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        secondEnableLinkButton = new QPushButton(gridLayoutWidget_2);
        secondEnableLinkButton->setObjectName(QString::fromUtf8("secondEnableLinkButton"));

        gridLayout->addWidget(secondEnableLinkButton, 4, 3, 1, 1);

        firstDistanceSpinBox = new QSpinBox(gridLayoutWidget_2);
        firstDistanceSpinBox->setObjectName(QString::fromUtf8("firstDistanceSpinBox"));

        gridLayout->addWidget(firstDistanceSpinBox, 2, 2, 1, 1);

        secondDistanceSpinBox = new QSpinBox(gridLayoutWidget_2);
        secondDistanceSpinBox->setObjectName(QString::fromUtf8("secondDistanceSpinBox"));

        gridLayout->addWidget(secondDistanceSpinBox, 4, 2, 1, 1);

        firstToNodeLabel = new QLabel(gridLayoutWidget_2);
        firstToNodeLabel->setObjectName(QString::fromUtf8("firstToNodeLabel"));

        gridLayout->addWidget(firstToNodeLabel, 2, 1, 1, 1);

        secondToNodeLabel = new QLabel(gridLayoutWidget_2);
        secondToNodeLabel->setObjectName(QString::fromUtf8("secondToNodeLabel"));

        gridLayout->addWidget(secondToNodeLabel, 4, 1, 1, 1);

        secondFromNodeLabel = new QLabel(gridLayoutWidget_2);
        secondFromNodeLabel->setObjectName(QString::fromUtf8("secondFromNodeLabel"));

        gridLayout->addWidget(secondFromNodeLabel, 4, 0, 1, 1);

        label_4 = new QLabel(gridLayoutWidget_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 1, 1, 1, 1);

        label_3 = new QLabel(gridLayoutWidget_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QFont font;
        font.setItalic(false);
        label_3->setFont(font);

        gridLayout->addWidget(label_3, 1, 2, 1, 1);

        firstFromNodeLabel = new QLabel(gridLayoutWidget_2);
        firstFromNodeLabel->setObjectName(QString::fromUtf8("firstFromNodeLabel"));

        gridLayout->addWidget(firstFromNodeLabel, 2, 0, 1, 1);

        firstFromNodeLabel_2 = new QLabel(gridLayoutWidget_2);
        firstFromNodeLabel_2->setObjectName(QString::fromUtf8("firstFromNodeLabel_2"));

        gridLayout->addWidget(firstFromNodeLabel_2, 1, 0, 1, 1);

        firstEnableLinkButton = new QPushButton(gridLayoutWidget_2);
        firstEnableLinkButton->setObjectName(QString::fromUtf8("firstEnableLinkButton"));

        gridLayout->addWidget(firstEnableLinkButton, 2, 3, 1, 1);

        label = new QLabel(gridLayoutWidget_2);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 1, 3, 1, 1);


        gridLayout_2->addLayout(gridLayout, 1, 0, 1, 1);


        retranslateUi(LinkInfoDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), LinkInfoDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), LinkInfoDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(LinkInfoDialog);
    } // setupUi

    void retranslateUi(QDialog *LinkInfoDialog)
    {
        LinkInfoDialog->setWindowTitle(QApplication::translate("LinkInfoDialog", "Insert Links", 0, QApplication::UnicodeUTF8));
        secondEnableLinkButton->setText(QApplication::translate("LinkInfoDialog", "Disable\n"
"Link", 0, QApplication::UnicodeUTF8));
        firstToNodeLabel->setText(QApplication::translate("LinkInfoDialog", "ToNode", 0, QApplication::UnicodeUTF8));
        secondToNodeLabel->setText(QApplication::translate("LinkInfoDialog", "ToNode", 0, QApplication::UnicodeUTF8));
        secondFromNodeLabel->setText(QApplication::translate("LinkInfoDialog", "FromNode", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("LinkInfoDialog", "To Node", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("LinkInfoDialog", "Distance between\n"
" nodes", 0, QApplication::UnicodeUTF8));
        firstFromNodeLabel->setText(QApplication::translate("LinkInfoDialog", "FromNode", 0, QApplication::UnicodeUTF8));
        firstFromNodeLabel_2->setText(QApplication::translate("LinkInfoDialog", "FromNode", 0, QApplication::UnicodeUTF8));
        firstEnableLinkButton->setText(QApplication::translate("LinkInfoDialog", "Disable\n"
"Link", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("LinkInfoDialog", "Enable / Disable Link", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class LinkInfoDialog: public Ui_LinkInfoDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LINKINFODIALOG_H
