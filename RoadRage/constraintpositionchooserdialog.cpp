#include "constraintpositionchooserdialog.h"
#include "ui_constraintpositionchooserdialog.h"

ConstraintPositionChooserDialog::ConstraintPositionChooserDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConstraintPositionChooserDialog)
{
    ui->setupUi(this);
    connect(this->ui->buttonBox, SIGNAL(accepted()),
            this, SLOT(setAccepted()));
    this->isAccept=true;
}

ConstraintPositionChooserDialog::~ConstraintPositionChooserDialog()
{
    delete ui;
}

void ConstraintPositionChooserDialog::setAccepted()
{
    if(this->ui->acceptRadioButton->isChecked())
        this->isAccept=true;
    else
        this->isAccept=false;
}
