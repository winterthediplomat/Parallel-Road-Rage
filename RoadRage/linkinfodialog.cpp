#include "linkinfodialog.h"
#include "ui_linkinfodialog.h"

LinkInfoDialog::LinkInfoDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LinkInfoDialog)
{
    ui->setupUi(this);
}

LinkInfoDialog::~LinkInfoDialog()
{
    delete ui;
}

LinkInfoDialog::LinkInfoDialog(Node *firstSelected, Node *secondSelected,
                               QWidget *parent):
    QDialog(parent),
    ui(new Ui::LinkInfoDialog)
{
    ui->setupUi(this);
    //initializing private variables
    this->first=firstSelected;
    this->second=secondSelected;
    if(firstSelected and secondSelected)
    {
        this->firstToSecond=new Link(this->first, this->second);
        this->secondToFirst=new Link(this->second, this->first);
        this->isFirstLinkAvailable=true;
        this->isSecondLinkAvaiable=true;
    }

    //initializing ui details
    this->ui->firstFromNodeLabel->setText(this->first->text());
    this->ui->firstToNodeLabel->setText(this->second->text());
    this->ui->secondFromNodeLabel->setText(this->second->text());
    this->ui->secondToNodeLabel->setText(this->first->text());


    //connetti gli enable
    connect(ui->firstEnableLinkButton, SIGNAL(clicked()), this, SLOT(setEnabledFirst()));
    connect(ui->secondEnableLinkButton, SIGNAL(clicked()), this, SLOT(setEnabledSecond()));
    connect(ui->firstDistanceSpinBox, SIGNAL(valueChanged(int)),
            this, SLOT(updateFirstLinkDistance()));
    connect(ui->secondDistanceSpinBox, SIGNAL(valueChanged(int)),
            this, SLOT(updateSecondLinkDistance()));
}

void LinkInfoDialog::setEnabledFirst()
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

void LinkInfoDialog::setEnabledSecond()
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

void LinkInfoDialog::updateFirstLinkDistance()
{
    this->firstToSecond->setDistance(this->ui->firstDistanceSpinBox->value());
}

void LinkInfoDialog::updateSecondLinkDistance()
{
    this->secondToFirst->setDistance(this->ui->secondDistanceSpinBox->value());
}

Node* LinkInfoDialog::getFirst()
{return this->first;}

Node* LinkInfoDialog::getSecond()
{return this->second;}

Link* LinkInfoDialog::getFirstToSecondLink()
{return this->firstToSecond;}

Link* LinkInfoDialog::getsecondToFirstLink()
{return this->secondToFirst;}

QList<Link* > LinkInfoDialog::links()
{
    QList<Link* > the_links;
    the_links.insert(0, getFirstToSecondLink());
    the_links.insert(1, getsecondToFirstLink());
    //if a link shouldn't be created, we set its distance to zero
    if(ui->firstEnableLinkButton->text()=="Enable Link") //link is disables
        the_links.at(0)->setDistance(0);
    if(ui->secondEnableLinkButton->text()=="Enable Link") //link is disables
        the_links.at(1)->setDistance(0);
    return the_links;
}
