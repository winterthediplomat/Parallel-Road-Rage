#include "reportviewerdialog.h"
#include "ui_reportviewerdialog.h"
#include "QDir"
#include "iostream"
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
using namespace std;

ReportViewerDialog::ReportViewerDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ReportViewerDialog)
{
    ui->setupUi(this);
    cout<<"DEBUG: current working path is: "<<QDir::currentPath().toStdString()<<endl;
    ui->webView->setUrl(QUrl("outD.html"));
}

ReportViewerDialog::~ReportViewerDialog()
{
    delete ui;
}

void ReportViewerDialog::on_pushButton_clicked()
{
    QFile actualReport("outD.html");
    actualReport.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream actualReportStream(&actualReport);

    QFile newReport(QFileDialog::getSaveFileName(
            this, "Save the report", ".", "HTML files (.html)"));
    newReport.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream newReportStream(&newReport);

    QString row;
    while((row=actualReportStream.readLine())!=NULL)
    {
        newReportStream<<row;
    }
    actualReport.close();
    newReport.close();
    QMessageBox okmsgbox;
    okmsgbox.setInformativeText("the report have been save successfully!");
    okmsgbox.setWindowTitle("Report Saved!");
    okmsgbox.exec();
}
