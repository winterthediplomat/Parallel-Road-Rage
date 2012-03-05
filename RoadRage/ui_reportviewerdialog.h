/********************************************************************************
** Form generated from reading UI file 'reportviewerdialog.ui'
**
** Created: Tue 7. Jun 21:52:51 2011
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REPORTVIEWERDIALOG_H
#define UI_REPORTVIEWERDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtWebKit/QWebView>

QT_BEGIN_NAMESPACE

class Ui_ReportViewerDialog
{
public:
    QDialogButtonBox *buttonBox;
    QWebView *webView;
    QPushButton *pushButton;

    void setupUi(QDialog *ReportViewerDialog)
    {
        if (ReportViewerDialog->objectName().isEmpty())
            ReportViewerDialog->setObjectName(QString::fromUtf8("ReportViewerDialog"));
        ReportViewerDialog->setWindowModality(Qt::ApplicationModal);
        ReportViewerDialog->resize(426, 317);
        ReportViewerDialog->setMouseTracking(false);
        ReportViewerDialog->setSizeGripEnabled(false);
        buttonBox = new QDialogButtonBox(ReportViewerDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(40, 280, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        webView = new QWebView(ReportViewerDialog);
        webView->setObjectName(QString::fromUtf8("webView"));
        webView->setGeometry(QRect(20, 10, 341, 251));
        webView->setUrl(QUrl("file:///home/alfateam123/Desktop/roadrage/RoadRage-build-desktop/outD.html"));
        pushButton = new QPushButton(ReportViewerDialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(370, 40, 51, 171));

        retranslateUi(ReportViewerDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), ReportViewerDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ReportViewerDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(ReportViewerDialog);
    } // setupUi

    void retranslateUi(QDialog *ReportViewerDialog)
    {
        ReportViewerDialog->setWindowTitle(QApplication::translate("ReportViewerDialog", "Report Viewer", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("ReportViewerDialog", "Save\n"
"Report", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ReportViewerDialog: public Ui_ReportViewerDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REPORTVIEWERDIALOG_H
