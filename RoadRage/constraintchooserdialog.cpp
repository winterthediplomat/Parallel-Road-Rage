#include "constraintchooserdialog.h"
#include "ui_constraintchooserdialog.h"
#include <QMessageBox>
#include <QtScript/QScriptEngine>
#include <QtScript/QScriptValue>


ConstraintChooserDialog::ConstraintChooserDialog(GraphInformationHandler *gih, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConstraintChooserDialog)
{

    ui->setupUi(this);
    this->gih=gih;
    this->currentConstraintListWidgetRow=-1;
    this->currentSetUpConstraintListWidgetRow=-1;
    foreach(QString name, this->gih->getConstraintNamesList())
    {
        this->ui->constraintsListWidget->insertItem(0, name);
    }

    this->loadSavedConstraints();


    connect(this->ui->constraintsListWidget, SIGNAL(currentRowChanged(int)),
            this, SLOT(currentRowChangedInConstraintListWidget(int)));
    connect(this->ui->setupConstraintsListWidget, SIGNAL(currentRowChanged(int)),
            this, SLOT(currentRowChangedInSetUpConstraintListWidget(int)));

    connect(this->ui->createPushButton, SIGNAL(clicked()),
            this, SLOT(createConstraintSlot()));
    connect(this->ui->deletePushButton, SIGNAL(clicked()),
            this, SLOT(deleteConstraintSlot()));
    connect(this->ui->updatePushButton, SIGNAL(clicked()),
            this, SLOT(updateConstraintSlot()));
}

ConstraintChooserDialog::~ConstraintChooserDialog()
{
    delete ui;
}

void ConstraintChooserDialog::currentRowChangedInConstraintListWidget(int currentRow)
{
    this->currentConstraintListWidgetRow=currentRow;
}

void ConstraintChooserDialog::currentRowChangedInSetUpConstraintListWidget(int currentRow)
{
    this->currentSetUpConstraintListWidgetRow=currentRow;
}

void ConstraintChooserDialog::createConstraintSlot()
{
    if(this->currentConstraintListWidgetRow!=-1)
    {
        QString constraintName=this->ui->constraintsListWidget->item(
                this->currentConstraintListWidgetRow
                )->text();
        bool isAccept=this->ui->acceptRadioButton->isChecked();
        bool isReject=this->ui->rejectRadioButton->isChecked();
        if(!isAccept && !isReject)
        {
            QMessageBox::critical(this, "u mad bro?", "you have to choose the constraint is accept or reject",
                                  QMessageBox::Ok);
            return;
        }
        this->gih->launchConstraintDialog(constraintName, isAccept?true:false);
        //QListWidget this->ui->constraintsListWidget->item(this->currentRow);
    }
    //currentConstraintListWidgetRow==-1
    //means that no constraint must be created.
    loadSavedConstraints();
}

void ConstraintChooserDialog::deleteConstraintSlot()
{
    if(this->currentSetUpConstraintListWidgetRow!=-1)
    {
        cout<<"# of accept constraints: "<<this->gih->getAcceptedConstraints().count()<<endl;
        cout<<"current row is: "<<this->currentSetUpConstraintListWidgetRow<<endl;
        if(!this->isAcceptConstraint())
        {
            cout<<"reject constraint!"<<endl;
            //is a reject constraint
            int offset=this->currentSetUpConstraintListWidgetRow-this->gih->getAcceptedConstraints().count();
            cout<<"offset: "<<offset<<endl;
            this->gih->removeRejectedConstraint(
                        this->gih->getRejectedConstraints().at(offset)
                        );
        }
        else
        {
            cout<<"accept constraint!"<<endl;
            //is an accept constraint
            this->gih->removeAcceptedConstraint(
                        this->gih->getAcceptedConstraints().at(
                            this->currentSetUpConstraintListWidgetRow)
                        );
        }

        //this->ui->setupConstraintsListWidget->removeItemWidget(
        //            this->ui->setupConstraintsListWidget->item(
        //                this->currentSetUpConstraintListWidgetRow));
    }
    else
    {
        QMessageBox::critical(this,
                    "can't delete a not-specified constraint",
                    "I can not delete a constraint, because you have not specified it!");
    }
    this->loadSavedConstraints();
}

void ConstraintChooserDialog::updateConstraintSlot()
{
    /*
      quick and dirty method to update a constraint:
      delete it and lets user recreate it with new parameters.

    //QString name=this->ui->setupConstraintsListWidget->itemAt(this->currentRowChangedInSetUpConstraintListWidget)->text();
    //bool isAccept=this->isAcceptConstraint();
    //if(isAccept)
    //    this->gih->removeAcceptedConstraint(this->currentSetUpConstraintListWidgetRow);
    //else
    //    this->gih->removeRejectedConstraint(this->currentSetUpConstraintListWidgetRow);
    //this->gih->launchConstraintDialog(name, isAccept);
    */
    loadSavedConstraints();
}

void ConstraintChooserDialog::loadSavedConstraints()
{

    //deleting old data
    /*
      //FUUUUUUUU~, why are you modifying condition variable into the cycle?
    for(int row=0; row<this->ui->setupConstraintsListWidget->count(); row++)
        this->ui->setupConstraintsListWidget->removeItemWidget(
                this->ui->setupConstraintsListWidget->item(0) //was: row
                );
    */
    //GTFO, I'm going to play Global Thermonuclear War! (Wargame is the game!)
    this->ui->setupConstraintsListWidget->clear();


    //now we can add new data!
    QVector<Constraint*> actualSavedConstraints=this->gih->getAcceptedConstraints();
    actualSavedConstraints+=this->gih->getRejectedConstraints();
    foreach(Constraint *constr, actualSavedConstraints)
    {
        QScriptValue value;
        QScriptEngine engine;
        //"(%1)" trick is used also in JavaScript to solve "invalid label" error
        //when retrieving data via AJAX in JSON format
        value=engine.evaluate(QString("(%1)['name']").arg(constr->generateJSON()));
        if(engine.hasUncaughtException())
        {
            cout<<"uncaught exception while evaluating constraint"<<endl;
            constr->printName();
            cout<<"---------------------"<<endl;
        }
        else
        {
            cout<<"name=="<<value.toString().toStdString()<<endl;
            this->ui->setupConstraintsListWidget->addItem(value.toString());
        }
    }

}

bool
ConstraintChooserDialog::isAcceptConstraint()
{
    //accept constraints are put before the reject ones.
    //we need to add 1 because 1>0 ;D
    return (this->currentSetUpConstraintListWidgetRow+1)<this->gih->getAcceptedConstraints().count();
}
