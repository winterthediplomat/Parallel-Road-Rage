#include "solutiontestingdialog.h"
#include <QMessageBox>
#include "ui_solutiontestingdialog.h"

SolutionTestingDialog::SolutionTestingDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SolutionTestingDialog)
{
    ui->setupUi(this);
}

SolutionTestingDialog::~SolutionTestingDialog()
{
    delete ui;
}

void
SolutionTestingDialog::setGIH(GraphInformationHandler *gih)
{
    this->gih=gih;
}

void
SolutionTestingDialog::scoreCalculation(bool isScore)
{
    this->isScoreCalculation=isScore;
}

void
SolutionTestingDialog::on_addSolutionPushButton_clicked()
{
    QString solution=this->ui->solutionLineEdit->text();
    if(!solution.isEmpty())
    {
        Path testedPath=this->gih->generateDefaultPath();
        foreach(QString str, solution.split(";"))
        {
            testedPath.appendPoint(str.toUInt());
        }
        unsigned int score=0;
        QVector<Constraint*> constraints=this->gih->getAcceptedConstraints();
        constraints+=this->gih->getRejectedConstraints();
        foreach(Constraint* constr, constraints)
        {
            if(this->isScoreCalculation)
                score+=constr->calculateSolutionScore(testedPath);
            else
                score+=constr->isRespected(testedPath)?1:0;
            constr->printName();
            cout<<"actual score is: "<<score<<endl;
        }
        QString textToBeInserted=QString("%1 --> %2/%3").arg(solution,
                                               QString::number(score),
                                               QString::number(this->isScoreCalculation?constraints.size()*this->gih->getNodes().size():constraints.size())
                                                             );
        this->ui->solutionListWidget->addItem(textToBeInserted);
    }
}

void
SolutionTestingDialog::on_helpPushButton_clicked()
{
    QMessageBox::information(this,"help", "insert items as numbers (first node is 0, second if 1 and so on),\nseparated by semicolons (;)");
}
