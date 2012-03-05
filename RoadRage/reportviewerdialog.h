#ifndef REPORTVIEWERDIALOG_H
#define REPORTVIEWERDIALOG_H

#include <QDialog>

namespace Ui {
    class ReportViewerDialog;
}

class ReportViewerDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ReportViewerDialog(QWidget *parent = 0);
    ~ReportViewerDialog();

private:
    Ui::ReportViewerDialog *ui;

private slots:
    void on_pushButton_clicked();
};

#endif // REPORTVIEWERDIALOG_H
