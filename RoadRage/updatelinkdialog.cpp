#include "updatelinkdialog.h"
#include "ui_updatelinkdialog.h"

UpdateLinkDialog::UpdateLinkDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UpdateLinkDialog)
{
    ui->setupUi(this);
}

UpdateLinkDialog::~UpdateLinkDialog()
{
    delete ui;
}

UpdateLinkDialog::UpdateLinkDialog(unsigned int first, unsigned int second, QString firstText, QString secondText, QWidget *parent):
    QDialog(parent),
    ui(new Ui::UpdateLinkDialog)
{
    ui->setupUi(this);
    //unsigned int INT_MAX=2147483647;
    //initializing private variables
    this->firstDistance=first;
    this->secondDistance=second;
    this->isFirstLinkAvailable=true;
    this->isSecondLinkAvaiable=true;

    //initializing ui details
    this->ui->firstFromNodeLabel->setText(firstText);
    this->ui->firstToNodeLabel->setText(secondText);
    this->ui->secondFromNodeLabel->setText(secondText);
    this->ui->secondToNodeLabel->setText(firstText);
    this->ui->firstDistanceSpinBox->setValue(firstDistance);
    this->ui->secondDistanceSpinBox->setValue(secondDistance);
    this->ui->firstDistanceSpinBox->setMaximum(INT_MAX);
    this->ui->secondDistanceSpinBox->setMaximum(INT_MAX);
    this->ui->firstDistanceSpinBox->setMinimum(0);
    this->ui->secondDistanceSpinBox->setMinimum(0);


    //connetti gli enable
    connect(ui->firstEnableLinkButton, SIGNAL(clicked()), this, SLOT(setEnabledFirst()));
    connect(ui->secondEnableLinkButton, SIGNAL(clicked()), this, SLOT(setEnabledSecond()));
    connect(ui->firstDistanceSpinBox, SIGNAL(valueChanged(int)),
            this, SLOT(updateFirstLinkDistance()));
    connect(ui->secondDistanceSpinBox, SIGNAL(valueChanged(int)),
            this, SLOT(updateSecondLinkDistance()));
}

void UpdateLinkDialog::setEnabledFirst()
{
    this->isFirstLinkAvailable=!this->isFirstLinkAvailable;
    this->ui->firstDistanceSpinBox->setEnabled(this->isFirstLinkAvailable);
    if(!this->isFirstLinkAvailable)
    {
        this->ui->firstEnableLinkButton->setText("Enable Link");
    }
    else
    {
        this->ui->firstEnableLinkButton->setText("Disable Link");
    }
}

void UpdateLinkDialog::setEnabledSecond()
{
    this->isSecondLinkAvaiable=!this->isSecondLinkAvaiable;
    this->ui->secondDistanceSpinBox->setEnabled(this->isSecondLinkAvaiable);
    if(!this->isSecondLinkAvaiable)
    {
        this->ui->secondEnableLinkButton->setText("Enable Link");
    }
    else
    {
        this->ui->secondEnableLinkButton->setText("Disable Link");
    }
}

void UpdateLinkDialog::updateFirstLinkDistance()
{
    this->firstDistance=this->ui->firstDistanceSpinBox->value();
}

void UpdateLinkDialog::updateSecondLinkDistance()
{
    this->secondDistance=(this->ui->secondDistanceSpinBox->value());
}

unsigned int UpdateLinkDialog::getFirst()
{
    if(this->ui->firstEnableLinkButton->text()=="Enable Link")
        this->firstDistance=0;
    return this->firstDistance;
}

unsigned int UpdateLinkDialog::getSecond()
{
    if(this->ui->secondEnableLinkButton->text()=="Enable Link")
        this->secondDistance=0;
    return this->secondDistance;
}


QList<unsigned int> UpdateLinkDialog::links()
{
    QList<unsigned int> the_links;
    the_links.insert(0, getFirst());
    the_links.insert(1, getSecond());
    return the_links;
}
