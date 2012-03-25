#include "maxlengthconstraintdialog.h"
#include "ui_maxlengthconstraintdialog.h"
//#include "QMessageBox"

MaxLengthConstraintDialog::MaxLengthConstraintDialog(GraphInformationHandler *gih,
                                         QWidget *parent) :
    ConstraintDialog(parent),
    ui(new Ui::MaxLengthConstraintDialog)
{
    ui->setupUi(this);
    this->gih=gih;
    this->ui->spinBox->setMaximum(this->gih->getNodes().size());
    connect(this->ui->buttonBox, SIGNAL(accepted()),
            this, SLOT(buttonBoxAcceptedSlot()));
}

MaxLengthConstraintDialog::~MaxLengthConstraintDialog()
{
    delete ui;
}

void MaxLengthConstraintDialog::buttonBoxAcceptedSlot()
{
    this->constraintObj=new MaxLengthConstraint();
    this->constraintObj->setMaxLength(this->ui->spinBox->value());
    //cout<<"added MaxLengthConstraint obj into accept constraints"<<endl;
    //this->gih->addAcceptConstraint(mlc);
}

//MaxLengthConstraint*
Constraint*
MaxLengthConstraintDialog::getConstraintObj()
{
    return this->constraintObj;
}
