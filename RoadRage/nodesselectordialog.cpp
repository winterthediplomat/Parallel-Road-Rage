#include "nodesselectordialog.h"
#include "ui_nodesselectordialog.h"
#include "iostream"
using namespace std;

NodesSelectorDialog::NodesSelectorDialog(GraphInformationHandler *gih, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NodesSelectorDialog)
{
    cout<<"hello by NodesSelectorDialog!"<<endl;
    ui->setupUi(this);
    this->gih=gih;
    //charging comboboxes
    this->setupComboBoxes();
    cout<<"NodesSelectorDialog->ui->firstNodeComboBox has "<<ui->firstNodeListWidget->count()<<" items"<<endl;
    cout<<"NodesSelectorDialog->ui->secondNodeComboBox has "<<ui->secondNodeListWidget->count()<<" items"<<endl;
    //this->ui->firstNodeListWidget->setCurrentIndex(0);
    //this->ui->secondNodeListWidget->setCurrentIndex(0);
    this->firstIndex=0;
    this->secondIndex=0;
}

NodesSelectorDialog::~NodesSelectorDialog()
{
    delete ui;
}

void NodesSelectorDialog::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}


int NodesSelectorDialog::getFirstNodeIndex()
{return this->firstIndex;}

int NodesSelectorDialog::getSecondNodeIndex()
{return this->secondIndex;}


void NodesSelectorDialog::setupComboBoxes()
{
    cout<<"GraphInformationHandler::getNodes() has"<<gih->getNodes().count()<<"items"<<endl;
   for(unsigned int index=0; index<gih->getNodes().count(); index++)
   {
        cout<<"added a node in comboboxes"<<endl;
        Node *actual=gih->getNodeByIndex(index);
        cout<<(this->ui->firstNodeListWidget!=NULL)<<endl;
        cout<<actual->text().toStdString()<<endl;
        this->ui->firstNodeListWidget->addItem(actual->text());
        this->ui->secondNodeListWidget->addItem(actual->text());
   }
}

void NodesSelectorDialog::on_firstNodeListWidget_currentRowChanged(int currentRow)
{
    //with this trick we should get a faster response!
    this->firstIndex=currentRow;
    Link* the_link=gih->getTheLinkByNodes(gih->getNodeByIndex(this->firstIndex),
                           gih->getNodeByIndex(this->secondIndex));
    if(the_link)
    {
        cout<<"a link between nodes exists!"<<endl;
        this->ui->linkLabel->setText("a link between nodes exists!");
        cout<<"the distance between nodes is "<<the_link->distance()<<endl;
        this->ui->distanceLabel->setText("the distance between nodes is: "+the_link->distance());
    }
    else if(this->firstIndex==this->secondIndex)
    {
        cout<<"a link between nodes does not exist!"<<endl;
        this->ui->linkLabel->setText("a link between nodes does not exist!");
        cout<<"the distance between nodes is 0"<<endl;
        this->ui->distanceLabel->setText("the distance between nodes is: 0");
    }
    else
    {
        QList<unsigned int> distance;
        QList<int> previous;
        QList<bool> visited;
        this->gih->execDijkstra(this->firstIndex,
                                this->secondIndex,
                                distance,
                                previous,
                                visited
                                );
        cout<<"the distance between nodes is "<<distance[secondIndex]<<endl;
        this->ui->distanceLabel->setText(QString("the distance between nodes is: %1").arg(
                distance[this->secondIndex])
                                         );
        cout<<"a link between nodes does not exist!"<<endl;
        this->ui->linkLabel->setText("a link between nodes does not exist!");
    }
}


void NodesSelectorDialog::on_secondNodeListWidget_currentRowChanged(int currentRow)
{
    //with this trick we should get a faster response!
    this->secondIndex=currentRow;
    Link* the_link=gih->getTheLinkByNodes(gih->getNodeByIndex(this->firstIndex),
                           gih->getNodeByIndex(this->secondIndex));
    if(the_link)
    {
        this->ui->linkLabel->setText("a link between nodes exists!");
        this->ui->distanceLabel->setText(QString("the distance between nodes is: %1").arg(
                QString::number(the_link->distance())));
    }
    else if(this->firstIndex==this->secondIndex)
    {
        this->ui->linkLabel->setText("a link between nodes does not exist!");
        this->ui->distanceLabel->setText("the distance between nodes is: 0");
    }
    else
    {

        QList<unsigned int> distance;
        QList<int> previous;
        QList<bool> visited;
        this->gih->execDijkstra(this->firstIndex,
                                this->secondIndex,
                                distance,
                                previous,
                                visited
                                );
        this->ui->distanceLabel->setText(QString("the distance between nodes is: %1").arg(
                QString::number(distance[this->secondIndex]))
                                         );
        this->ui->linkLabel->setText("a link between nodes does not exist!");
    }
}

bool NodesSelectorDialog::isSwitchNodesChecked()
{return this->ui->switchCheckBox->checkState()==Qt::Checked;}

void NodesSelectorDialog::setSwitchNodesChecked(bool state, bool isStateExchangeable)
{
    this->ui->switchCheckBox->setChecked(state);
    this->ui->switchCheckBox->setCheckable(isStateExchangeable);
}

void NodesSelectorDialog::setDistanceLabelVisible(bool isVisible)
{
    this->ui->distanceLabel->setVisible(isVisible);
}

void NodesSelectorDialog::setLinkExistingLabelVisible(bool isVisible)
{
    this->ui->linkLabel->setVisible(isVisible);
}
