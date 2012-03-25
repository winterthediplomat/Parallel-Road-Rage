#include "nodesselectordialog.h"
#include "ui_nodesselectordialog.h"
#include "iostream"
#include "solvers/dijkstra/dijkstrasolver.h"
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
    this->firstIndex=-1;
    this->secondIndex=-1;
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
    this->firstIndex=currentRow;
    if(this->secondIndex!=-1)
        this->modifyResponse(this->firstIndex, this->secondIndex);
}


void NodesSelectorDialog::on_secondNodeListWidget_currentRowChanged(int currentRow)
{
    this->secondIndex=currentRow;
    if(this->firstIndex!=-1)
        this->modifyResponse(this->firstIndex, this->secondIndex);
}

bool NodesSelectorDialog::isSwitchNodesChecked()
{return this->ui->switchCheckBox->checkState()==Qt::Checked;}

void NodesSelectorDialog::setSwitchNodesChecked(bool state, bool isStateExchangeable)
{
    this->ui->switchCheckBox->setChecked(state);
    this->ui->switchCheckBox->setCheckable(isStateExchangeable);
    //if you can't change state of checkbox, don't even show it!
    this->ui->switchCheckBox->setVisible(isStateExchangeable);
}

void NodesSelectorDialog::setDistanceLabelVisible(bool isVisible)
{
    this->ui->distanceLabel->setVisible(isVisible);
}

void NodesSelectorDialog::setLinkExistingLabelVisible(bool isVisible)
{
    this->ui->linkLabel->setVisible(isVisible);
}


void NodesSelectorDialog::modifyResponse(int fromNodeRow, int toNodeRow)
{
    cout<<"-----------------------------------------------"<<endl;
    cout<<"there is a link from "<<fromNodeRow<<" and "<<toNodeRow<<"?"<<endl;
    Link* the_link=gih->getTheLinkByNodes(gih->getNodeByIndex(this->firstIndex),
                           gih->getNodeByIndex(this->secondIndex));
    if(the_link)
    {
        cout<<"a link between nodes exists!"<<endl;
        this->ui->linkLabel->setText("a link between nodes exists!");
        unsigned int distance=the_link->distance();
        if(the_link->distance()==0 || the_link->distance()==INT_MAX)
        {
            //f**ki' stupid check related to DiagramWindow::addLink
            distance=this->getDijkstraLength(fromNodeRow, toNodeRow);
            this->ui->linkLabel->setText("a link between nodes does not exists, but Dijkstra calculated it!");
        }

        cout<<"the distance between nodes is "<<distance<<endl;
        this->ui->distanceLabel->setText(QString("the distance between nodes is: %1").arg(QString::number(distance)));
    }
    else if(this->firstIndex==this->secondIndex)
    {
        cout<<"looking for a way to reach the same node!"<<endl;
        this->ui->linkLabel->setText("looking for a way to go where already are you? stop!");
        cout<<"the distance between nodes is 0"<<endl;
        this->ui->distanceLabel->setText("the distance between nodes is: 0");
    }
    else
    {
        cout<<"calculating solution!!!"<<endl;
        unsigned int distance=this->getDijkstraLength(fromNodeRow, toNodeRow);
        cout<<"the distance between nodes is "<<distance<<endl;
        this->ui->distanceLabel->setText(QString("the distance between nodes is: %1").arg(distance));
        cout<<"a link between nodes does not exist!"<<endl;
        this->ui->linkLabel->setText("a link does not exists, but Dijkstra calculated it");
    }
}

unsigned int
NodesSelectorDialog::getDijkstraLength(int fromNodeRow, int toNodeRow)
{
    DijkstraSolver dijkstra;
    dijkstra.setGIH(this->gih);
    Path fasterPath;
    unsigned int distance;

    dijkstra.getSolutions(this->gih->getNodeByIndex(fromNodeRow)->text(),
                          this->gih->getNodeByIndex(toNodeRow)->text(),
                          fasterPath, distance);
    cout<<"printing path"<<endl;
    fasterPath.print();
    return distance;
    //return this->gih->getLengthOfPath(fasterPath);
}
