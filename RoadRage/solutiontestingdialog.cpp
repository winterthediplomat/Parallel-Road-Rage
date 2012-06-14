#include "solutiontestingdialog.h"
#include <QMessageBox>
#include "ui_solutiontestingdialog.h"
#include "constraints/AllConnectedToEachOther/allconnectedtoeachother.h"
#include "constraints/LastPointConnectedToFirst/lastpointconnectedtofirstconstraint.h"

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

Path
SolutionTestingDialog::generatePathFromString(QString givenPath)
{
    Path testedPath=this->gih->generateDefaultPath();
    foreach(QString point, givenPath.split(";"))
    {
        testedPath.appendPoint(point.toUInt());
    }
    return testedPath;
}

void
SolutionTestingDialog::on_addSolutionPushButton_clicked()
{
    QString solution=this->ui->solutionLineEdit->text();
    if(!solution.isEmpty())
    {
        Path testedPath=this->generatePathFromString(solution);
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

void
SolutionTestingDialog::on_solutionListWidget_itemClicked(QListWidgetItem* item)
{
    unsigned int arrowPosition=item->text().indexOf(" -->");
    QString pathStringFromItem=item->text();
    pathStringFromItem.chop(item->text().size()-arrowPosition);
    Path pathFromItem=this->generatePathFromString(pathStringFromItem);
    AllConnectedToEachOther *acte=new AllConnectedToEachOther();
    LastPointConnectedToFirstConstraint *lpctf=
            new LastPointConnectedToFirstConstraint();
    acte->setGIH(this->gih);
    lpctf->setGIH(this->gih);
    if(acte->isRespected(pathFromItem) && lpctf->isRespected(pathFromItem))
    {
        this->ui->highlightedPathLabel->setText("The path is highlighted!");
        //for(unsigned int i=0; i<pathFromItem.getPath.size()-1; i++)
        for(unsigned int i=0; i<pathFromItem.getPath().size(); i++)
        {
            QString start=pathFromItem.getNameByPoint(pathFromItem.getPath().at(i));
            QString end=pathFromItem.getNameByPoint(pathFromItem.getPath().at(
                                                        i==pathFromItem.getPath().size()-1?0:i+1));
            Link *da_link=this->gih->getTheLinkByNodes(
                        this->gih->getNodeByText(start),
                        this->gih->getNodeByText(end));
            if(da_link)
            {
                da_link->setColor(Qt::blue);
                da_link->trackNodes();
                da_link->setZValue(0);
            }
        }

    }
    else
    {
        this->ui->highlightedPathLabel->setText("This path cannot be highlighted!");
    }
}
