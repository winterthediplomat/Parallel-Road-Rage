#include "QtGui"

#include "diagramwindow.h"
#include "link.h"
#include "node.h"
#include "propertiesdialog.h"
#include "linkinfodialog.h"
#include "updatelinkdialog.h"
#include "reportviewerdialog.h"
#include "nodesselectordialog.h"
#include "linksdescriptor.h"
//#include "iostream"


#include "constraintchooserdialog.h"
#include "solutiontestingdialog.h"

#include "path.h"
#include "solvers/backtracking/btsolver.h"
#include "solvers/genetic/geneticengine.h"
//#include "constraints/AllDifferentElements/alldifferentelementsconstraint.h"
//#include "constraints/MaxLength/maxlengthconstraint.h"

//#include "constraints.h"

using namespace std;


DiagramWindow::DiagramWindow()
{
    cout<<"creato il DiagramWindow"<<endl;
    scene = new QGraphicsScene(0, 0, 600, 500);

    view = new QGraphicsView;
    view->setScene(scene);
    view->setDragMode(QGraphicsView::RubberBandDrag);
    view->setRenderHints(QPainter::Antialiasing
                         | QPainter::TextAntialiasing);

    view->setContextMenuPolicy(Qt::ActionsContextMenu);
    setCentralWidget(view);

    minZ = 0;
    maxZ = 0;
    seqNumber = 0;

    createActions();
    createMenus();
    createToolBars();

    connect(scene, SIGNAL(selectionChanged()),
            this, SLOT(updateActions()));

    setWindowTitle(tr("Road Rage"));
    updateActions();

    gih=new GraphInformationHandler();
    this->currentFile="";
    isGraphModified=false;
    //this->linkDescriptions=new QList<QGraphicsTextItem*>();

}

void DiagramWindow::addNode()
{
    Node *node = new Node(gih);
    node->setText(tr("Node %1").arg(seqNumber + 1));
    setupNode(node);
    //node->setGIH(gih);
    gih->addNode(node);
    cout<<"aggiunto un nodo!"<<node<<endl;
    if (!gih->getNodes().contains(node))
    {
        cout<<"il nodo NON è stato effettivamente aggiunto"<<endl;
    }
    this->modified();
}

//GraphInformationHandler* DiagramWindow::getGIH()
//{return this->gih;}

void DiagramWindow::addLink()
{
    NodePair nodes = selectedNodePair();
    if (nodes == NodePair())
        return;

    LinkInfoDialog *lid=new LinkInfoDialog(nodes.first, nodes.second, 0);

    if(lid->exec()==QDialog::Accepted)
    {

        foreach(Link* link, lid->links())
        {
            if(link!=NULL and this->gih->addLink(link))
            {
                cout<<"added!"<<endl;
                scene->addItem(link);

                link->fromNode()->addLink(link);
                link->toNode()->addLink(link);
                if(link->distance()==0) //nel caso il nodo non venga creato dall'utente
                    link->setDistance(2147483647);
                link->setDescription(
                        QString("%1->%2=%3").arg(link->fromNode()->text(),
                              link->toNode()->text(),
                              QString::number(link->distance()))
                        );
            }
        }
        /*cout<<"creating LinksDescriptor"<<endl;
        LinksDescriptor *ld=new LinksDescriptor(
                lid->links().first(), lid->links().last(),
                scene->addText(
                        lid->links().first()->description()+QString("\n")+lid->links().last()->description())
                );

        ld->getDescription()->setPos(lid->links().first()->getMidPoint().first, //x
                                     lid->links().first()->getMidPoint().second); //y
        gih->addLinksDescriptor(ld);
        */
        this->modified();
    }
}

void DiagramWindow::updateLinks()
{
    //nodes got by same link
    if(this->selectedLink()==NULL)
    {
        QMessageBox* msgbox=new QMessageBox(QMessageBox::Warning, "No links selected", "No links are selected! Please select a link.", QMessageBox::Ok);
        msgbox->show();
    }
    Node* first=this->selectedLink()->fromNode();
    Node* second=this->selectedLink()->toNode();

    QList<Link*> links=this->gih->getLinksByNodes(first, second);
    UpdateLinkDialog *uld=new UpdateLinkDialog(
                links.first()->distance(), links.last()->distance(),
                links.first()->fromNode()->text(), links.first()->toNode()->text());
    if(uld->exec()==QDialog::Accepted)
    {
        gih->updateLink(links.first(), uld->getFirst());
        gih->updateLink(links.last(), uld->getSecond());
        this->modified();
    }
}

void DiagramWindow::del(QList<QGraphicsItem *> items)
{
    cout<<"entered in DiagramWindow::del"<<endl;
    if (items==QList<QGraphicsItem*>())
        items = scene->selectedItems();
    QMutableListIterator<QGraphicsItem *> i(items);
    while (i.hasNext()) {
        QGraphicsItem *actual_item=i.next();
        cout<<"the iterator has a next!"<<endl;
        Link *link = dynamic_cast<Link *>(actual_item);
        Node *node = dynamic_cast<Node *>(actual_item);
        if (link) {
            cout<<"removing link "<<link<<endl;
            cout<<"asked help to GraphInformationHandler"<<endl;
            this->gih->removeLink(link);
            delete link;
            cout<<"deleted!"<<endl;
            i.remove();
        }
        if (node)
        {
            cout<<"removing node"<<endl;
            cout<<"asked help to GraphInformationHandler"<<endl;
            this->gih->removeNode(node);
            cout<<"deleted node!"<<endl;
            i.remove();
        }
    }

    qDeleteAll(items);
    this->modified();
}

void DiagramWindow::cut()
{
    Node *node = selectedNode();
    if (!node)
        return;

    copy();
    delete node;
    this->modified();
}

void DiagramWindow::copy()
{
    Node *node = selectedNode();
    if (!node)
        return;

    QString str = QString("Node %1 %2 %3 %4")
                  .arg(node->textColor().name())
                  .arg(node->outlineColor().name())
                  .arg(node->backgroundColor().name())
                  .arg(node->text());
    QApplication::clipboard()->setText(str);
    this->modified();
}

void DiagramWindow::paste()
{
    QString str = QApplication::clipboard()->text();
    QStringList parts = str.split(" ");

    if (parts.count() >= 5 && parts.first() == "Node") {
        Node *node = new Node;
        node->setText(QStringList(parts.mid(4)).join(" "));
        node->setTextColor(QColor(parts[1]));
        node->setOutlineColor(QColor(parts[2]));
        node->setBackgroundColor(QColor(parts[3]));
        setupNode(node);
    }
    this->modified();
}

void DiagramWindow::bringToFront()
{
    ++maxZ;
    setZValue(maxZ);
}

void DiagramWindow::sendToBack()
{
    --minZ;
    setZValue(minZ);
}

void DiagramWindow::properties()
{
    Node *node = selectedNode();
    Link *link = selectedLink();

    if (node) {
        PropertiesDialog dialog(node, this);
        dialog.exec();
    } else if (link) {
        QColor color = QColorDialog::getColor(link->color(), this);
        if (color.isValid())
            link->setColor(color);
    }
}

void DiagramWindow::updateActions()
{
    bool hasSelection = !scene->selectedItems().isEmpty();
    bool isNode = (selectedNode() != 0);
    bool isLink=(selectedLink()!=0);
    bool isNodePair = (selectedNodePair() != NodePair());

    cutAction->setEnabled(isNode);
    copyAction->setEnabled(isNode);
    addLinkAction->setEnabled(isNodePair);
    deleteAction->setEnabled(hasSelection);
    bringToFrontAction->setEnabled(isNode);
    sendToBackAction->setEnabled(isNode);
    propertiesAction->setEnabled(isNode);
    updateLinkAction->setEnabled(isLink);


    foreach (QAction *action, view->actions())
        view->removeAction(action);

    foreach (QAction *action, editMenu->actions()) {
        if (action->isEnabled())
            view->addAction(action);
    }

}

void DiagramWindow::generateReport()
{
    if(isGraphModified) //call Dijkstra on a pre-evaluated graph is useless!
        this->gih->generateReport();
    isGraphModified=false;
    this->setWindowTitle(this->windowTitle().remove("\\*")); //remove only the star
    ReportViewerDialog *rvd= new ReportViewerDialog();
    rvd->show();
}

void DiagramWindow::createActions()
{
    exitAction = new QAction(tr("E&xit"), this);
    //exitAction->setShortcut(tr("Ctrl+Q"));
    connect(exitAction, SIGNAL(triggered()), this, SLOT(close()));

    addNodeAction = new QAction(tr("Add &Node"), this);
    //addNodeAction->setIcon(QIcon(":/images/node.png"));
    addNodeAction->setShortcut(tr("Ctrl+N"));
    connect(addNodeAction, SIGNAL(triggered()), this, SLOT(addNode()));

    addLinkAction = new QAction(tr("Add &Link"), this);
    //addLinkAction->setIcon(QIcon(":/images/link.png"));
    addLinkAction->setShortcut(tr("Ctrl+L"));
    connect(addLinkAction, SIGNAL(triggered()), this, SLOT(addLink()));

    deleteAction = new QAction(tr("&Delete"), this);
    //deleteAction->setIcon(QIcon(":/images/delete.png"));
    deleteAction->setShortcut(tr("Del"));
    connect(deleteAction, SIGNAL(triggered()), this, SLOT(del()));

    cutAction = new QAction(tr("Cu&t"), this);
    //cutAction->setIcon(QIcon(":/images/cut.png"));
    cutAction->setShortcut(tr("Ctrl+X"));
    connect(cutAction, SIGNAL(triggered()), this, SLOT(cut()));

    copyAction = new QAction(tr("&Copy"), this);
    //copyAction->setIcon(QIcon(":/images/copy.png"));
    copyAction->setShortcut(tr("Ctrl+C"));
    connect(copyAction, SIGNAL(triggered()), this, SLOT(copy()));

    pasteAction = new QAction(tr("&Paste"), this);
    //pasteAction->setIcon(QIcon(":/images/paste.png"));
    pasteAction->setShortcut(tr("Ctrl+V"));
    connect(pasteAction, SIGNAL(triggered()), this, SLOT(paste()));

    bringToFrontAction = new QAction(tr("Bring to &Front"), this);
    //bringToFrontAction->setIcon(QIcon(":/images/bringtofront.png"));
    connect(bringToFrontAction, SIGNAL(triggered()),
            this, SLOT(bringToFront()));

    sendToBackAction = new QAction(tr("&Send to Back"), this);
    //sendToBackAction->setIcon(QIcon(":/images/sendtoback.png"));
    connect(sendToBackAction, SIGNAL(triggered()),
            this, SLOT(sendToBack()));

    propertiesAction = new QAction(tr("P&roperties..."), this);
    connect(propertiesAction, SIGNAL(triggered()),
            this, SLOT(properties()));

    this->generateReportAction=new QAction(tr("Generate Report"), this);
    connect(generateReportAction, SIGNAL(triggered()),
            this, SLOT(generateReport()));

    this->updateLinkAction=new QAction(tr("Update links information"), this);
    connect(updateLinkAction, SIGNAL(triggered()),
            this, SLOT(updateLinks()));

    this->openGraphAction=new QAction(tr("Open graph"), this);
    connect(openGraphAction, SIGNAL(triggered()),
            this, SLOT(openGraph()));

    this->saveGraphAction=new QAction(tr("Save current graph"), this);
    connect(saveGraphAction, SIGNAL(triggered()),
            this, SLOT(saveGraph()));

    this->selectNodesAction=new QAction(tr("Select two nodes"), this);
    connect(selectNodesAction, SIGNAL(triggered()),
            this, SLOT(selectNodes()));

    this->switchNodesAction=new QAction(tr("Switch two nodes"), this);
    connect(switchNodesAction, SIGNAL(triggered()),
            this, SLOT(switchNodesSlot()));

    this->getDistanceAction=new QAction(tr("Get distance"), this);
    connect(getDistanceAction, SIGNAL(triggered()),
            this, SLOT(getDistanceSlot()));


    this->getBacktrackingTSPAction=new QAction(tr("launch backtracking for TSP"), this);
    connect(getBacktrackingTSPAction, SIGNAL(triggered()),
            this, SLOT(getBacktrackingTSPSlot()));

    //this->getDijkstraAction=new QAction(tr("calculate Dijkstra between two points"), this);
    //connect(getDijkstraAction, SIGNAL(triggered()),
    //        this, SLOT(getDijkstraSlot()));

    this->getFloodingAction=new QAction(tr("launch Genetic Engine"), this);
    connect(this->getFloodingAction, SIGNAL(triggered()),
            this, SLOT(getFloodingSlot()));

    this->chooseConstraintAction=new QAction(tr("choose a constraint"), this);
    connect(this->chooseConstraintAction, SIGNAL(triggered()),
            this, SLOT(chooseConstraintSlot()));

    this->testConstraintRespect=new QAction(tr("test constraint respect"), this);
    connect(this->testConstraintRespect, SIGNAL(triggered()),
            this, SLOT(testConstraintRespectSlot()));

    this->testConstraintScore=new QAction(tr("test constraint score"), this);
    connect(this->testConstraintScore, SIGNAL(triggered()),
            this, SLOT(testConstraintScoreSlot()));

}

void DiagramWindow::createMenus()
{
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(exitAction);

    fileMenu->addAction(this->saveGraphAction);
    fileMenu->addAction(this->openGraphAction);

    editMenu = menuBar()->addMenu(tr("&Edit"));
    editMenu->addAction(addNodeAction);
    editMenu->addAction(addLinkAction);
    editMenu->addAction(deleteAction);
    editMenu->addSeparator();
    editMenu->addAction(cutAction);
    editMenu->addAction(copyAction);
    editMenu->addAction(pasteAction);
    editMenu->addSeparator();
    editMenu->addAction(bringToFrontAction);
    editMenu->addAction(sendToBackAction);
    editMenu->addSeparator();
    editMenu->addAction(propertiesAction);
    editMenu->addAction(generateReportAction);
    editMenu->addAction(updateLinkAction);
    editMenu->addAction(selectNodesAction);

    solverMenu=menuBar()->addMenu(tr("&Solvers"));
    solverMenu->addAction(this->getBacktrackingTSPAction);
    solverMenu->addAction(this->getFloodingAction);

    testMenu=menuBar()->addMenu(tr("Testing"));
    testMenu->addAction(this->testConstraintRespect);
    testMenu->addAction(this->testConstraintScore);
}

void DiagramWindow::createToolBars()
{
    editToolBar = addToolBar(tr("Edit"));
    editToolBar->addAction(addNodeAction);
    editToolBar->addAction(addLinkAction);
    editToolBar->addAction(deleteAction);
    editToolBar->addSeparator();
    editToolBar->addAction(cutAction);
    editToolBar->addAction(copyAction);
    editToolBar->addAction(pasteAction);
    editToolBar->addSeparator();
    editToolBar->addAction(bringToFrontAction);
    editToolBar->addAction(sendToBackAction);

    utilityToolBar=addToolBar(tr("Utility"));
    utilityToolBar->addAction(this->selectNodesAction);
    utilityToolBar->addAction(this->switchNodesAction);
    utilityToolBar->addAction(this->generateReportAction);
    utilityToolBar->addAction(this->getDistanceAction);
    utilityToolBar->addAction(this->chooseConstraintAction);
}

void DiagramWindow::setZValue(int z)
{
    Node *node = selectedNode();
    if (node)
        node->setZValue(z);
}

void DiagramWindow::setupNode(Node *node)
{
    node->setPos(QPoint(80 + (100 * (seqNumber % 5)),
                        80 + (50 * ((seqNumber / 5) % 7))));
    scene->addItem(node);
    ++seqNumber;

    scene->clearSelection();
    node->setSelected(true);
    bringToFront();
}

Node *DiagramWindow::selectedNode() const
{
    QList<QGraphicsItem *> items = scene->selectedItems();
    if (items.count() == 1) {
        return dynamic_cast<Node *>(items.first());
    }
    else {
        return 0;
    }
}

Link *DiagramWindow::selectedLink() const
{
    QList<QGraphicsItem *> items = scene->selectedItems();
    if (items.count() == 1)
    {
        return dynamic_cast<Link *>(items.first());
    }
    else if(items.count()==2)
        return dynamic_cast<Link*>(items.first());
    else
    {
        return 0;
    }
}

DiagramWindow::NodePair DiagramWindow::selectedNodePair() const
{
    QList<QGraphicsItem *> items = scene->selectedItems();
    if (items.count() == 2) {
        Node *first = dynamic_cast<Node *>(items.first());
        Node *second = dynamic_cast<Node *>(items.last());
        if (first && second)
            return NodePair(first, second);
    }
    return NodePair();
}


void DiagramWindow::saveGraph()
{
    if(this->currentFile.isEmpty())
       this->currentFile=QFileDialog::getSaveFileName(
                this, "Save the graph", ".", "Text files (.txt)");
    if(this->currentFile.isEmpty())
        return;

    //writing the file
    QFile file(this->currentFile);
    file.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream out(&file);

    foreach(Node* actualNode, gih->getNodes())
    {
        out<<"Node;"<<actualNode->text()<<";"<<actualNode->x()<<";"<<actualNode->y()<<"\n";
    }
    foreach(Link* actualLink, gih->getLinks())
    {
        out<<"Link;"<<actualLink->fromNode()->text()<<";"<<actualLink->toNode()->text()<<";"<<actualLink->distance()<<"\n";
    }

    file.close();
    this->modified();

}

void DiagramWindow::openGraph()
{

    QString newFile=QFileDialog::getOpenFileName(
              this, "Open a saved graph", ".", "Text files (.txt);;");
    if(!newFile.isEmpty()) {this->currentFile=newFile;}

    //destroy all items in the scene, cleaning it
    //this->del(this->scene->items());

    foreach(Node *oldNode, gih->getNodes())
        gih->removeNode(oldNode);
    //don't delete the links because they're already deleted
    // in Node descructor
    cout<<"ok, deleted nodes!"<<endl;
    //foreach(Link *oldLink, gih->getLinks())
    //    gih->removeLink(oldLink);

    QFile file(this->currentFile);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream in(&file);
    QString row;
    while((row=in.readLine())!=NULL)
    {
        QStringList row_args=row.split(";");
        if(row_args.first()=="Node")
        {
            this->addNode();
            this->selectedNode()->setText(row_args.at(1));
            this->selectedNode()->setX(qreal(row_args.at(2).toInt()));
            this->selectedNode()->setY(qreal(row_args.at(3).toInt()));
        }
        else if(row_args.first()=="Link")
        {
            Node *firstNode=gih->getNodeByText(row_args.at(1));
            Node *secondNode=gih->getNodeByText(row_args.at(2));
            if(firstNode==NULL or secondNode==NULL)
            {return;}
            Link *the_link=new Link(firstNode, secondNode);
            gih->addLink(the_link);
            scene->addItem(the_link);

            the_link->fromNode()->addLink(the_link);
            the_link->toNode()->addLink(the_link);
            the_link->setDistance(row_args.at(3).toUInt());
            /*foreach(Link *first, gih->getLinks())
            {
                foreach(Link *second, gih->getLinks())
                {
                    if(first->fromNode()==second->toNode()
                        and first->toNode()==second->fromNode())
                    {
                        if(!gih->getLinksDescriptorByLinks(first, second)
                            and !gih->getLinksDescriptorByLinks(second, first))
                        {
                        LinksDescriptor *ld=new LinksDescriptor(
                                first, second,
                                scene->addText(
                                        first->description()+QString("\n")+second->description())
                                );

                        ld->getDescription()->setPos(first->getMidPoint().first, //x
                                                     first->getMidPoint().second); //y
                        gih->addLinksDescriptor(ld);
                        }
                    }
               }
            }*/

        }
        else {/* some sh*t I don't want to handle */}
    }
    this->modified();
}



void DiagramWindow::modified(const QString *givenFileName)
{
    isGraphModified=true;
    if(givenFileName==0)
        givenFileName=&this->currentFile;
    if(this->currentFile.isEmpty())
        givenFileName=new QString("untitled");
    if(!this->windowTitle().contains("\\*"))
    {
        this->setWindowTitle(QString("RoadRage")+QString(" - ")+*givenFileName+QString("*"));
    }
}

void DiagramWindow::selectNodes()
{
    RISELEZIONA_NODO:
    NodesSelectorDialog nsd(gih, 0);
    if (nsd.exec()==QDialog::Accepted)
    {
        unsigned int firstNodeIndex, secondNodeIndex;
        firstNodeIndex=nsd.getFirstNodeIndex();
        secondNodeIndex=nsd.getSecondNodeIndex();
        Link *the_link=gih->getTheLinkByNodes(
                gih->getNodeByIndex(firstNodeIndex),
                gih->getNodeByIndex(secondNodeIndex)
                );
        if(nsd.isSwitchNodesChecked())
        {
            cout<<"nsd.isSwitchNodesChecked() e\' veroooo!"<<endl;
            this->switchNodes(
                    gih->getNodeByIndex(firstNodeIndex),
                    gih->getNodeByIndex(secondNodeIndex)
                    );
            this->gih->updateLinkTrack();
            return;
        }
        if(the_link)
        {
            //code copied and pasted by DiagramWindow::updateLinks()

            Node* first=the_link->fromNode();
            Node* second=the_link->toNode();

            QList<Link*> links=this->gih->getLinksByNodes(first, second);
            UpdateLinkDialog *uld=new UpdateLinkDialog(
                        links.first()->distance(), links.last()->distance(),
                        links.first()->fromNode()->text(), links.first()->toNode()->text());
            if(uld->exec()==QDialog::Accepted)
            {
                gih->updateLink(links.first(), uld->getFirst());
                gih->updateLink(links.last(), uld->getSecond());
                gih->updateLinkTrack();
                this->modified();
            }
        }
        else
        {
            if(firstNodeIndex!=secondNodeIndex)
            {

                    //code copied and pasted by DiagramWindow::addLink()
                    LinkInfoDialog *lid=new LinkInfoDialog(gih->getNodeByIndex(firstNodeIndex),
                                                           gih->getNodeByIndex(secondNodeIndex),
                                                           0);

                    if(lid->exec()==QDialog::Accepted)
                    {
                        foreach(Link* link, lid->links())
                        {
                            if(link!=NULL and this->gih->addLink(link))
                            {
                                cout<<"added!"<<endl;
                                scene->addItem(link);

                                link->fromNode()->addLink(link);
                                link->toNode()->addLink(link);
                                link->setDescription(
                                        QString("%1->%2=%3").arg(link->fromNode()->text(),
                                              link->toNode()->text(),
                                              QString::number(link->distance()))
                                        );
                            }
                        }
                        /*
                        LinksDescriptor *ld=new LinksDescriptor(
                                lid->links().first(), lid->links().last(),
                                scene->addText(
                                        lid->links().first()->description()+QString("\n")+lid->links().last()->description())
                                );

                        cout<<lid->links().first()->getMidPoint().first<<endl;
                        cout<<lid->links().first()->getMidPoint().second<<endl;
                        ld->getDescription()->setPos(lid->links().first()->getMidPoint().first, //x
                                                     lid->links().first()->getMidPoint().second); //y
                        gih->addLinksDescriptor(ld);
                        */
                        this->modified();
                    }
            }
            else
            {
                QMessageBox msgbox;
                msgbox.setWindowTitle(QString("link error"));
                msgbox.setInformativeText(QString("you can't connect a node to itself!"));
                msgbox.exec();
                goto RISELEZIONA_NODO;
            }
        }
        gih->updateLinkTrack();

    }
}


void DiagramWindow::switchNodes(Node *firstNode, Node *secondNode)
{
    cout<<"entrato in DiagramWindow::switchNodes!"<<endl;
    qreal firstX=firstNode->x(), firstY=firstNode->y();
    firstNode->setX(secondNode->x());
    firstNode->setY(secondNode->y());
    secondNode->setX(firstX);
    secondNode->setY(firstY);
    gih->updateLinkTrack();
}

void DiagramWindow::switchNodesSlot()
{
    NodesSelectorDialog nsd(gih, 0);
    nsd.setWindowTitle("select two nodes to switch");
    nsd.setSwitchNodesChecked(true, false);
    nsd.setDistanceLabelVisible(false);
    nsd.setLinkExistingLabelVisible(false);
    if(nsd.exec()==QDialog::Accepted)
    {
        this->switchNodes(
                gih->getNodeByIndex(nsd.getFirstNodeIndex()),
                gih->getNodeByIndex(nsd.getSecondNodeIndex())
                );
        this->gih->updateLinkTrack();
    }
}

void DiagramWindow::getBacktrackingTSPSlot()
{
    BTSolver bts;
    ////old way!
    ////AllDifferentElementsConstraint *adec=new AllDifferentElementsConstraint();
    ////MaxLengthConstraint* mlc=new MaxLengthConstraint();
    ////mlc->setMaxLength(3);
    //AllDifferentElementsConstraint *adec=new AllDifferentElementsConstraint();
    //we need casting. ok.
    //MaxLengthConstraint* mlc=(MaxLengthConstraint*)
    //               this->gih->createConstraint("MaxLength");
    //MaxLengthConstraint* mlc=(MaxLengthConstraint*)this->gih->getConstraintInterface("MaxLength")->getConstraintObj();
    //mlc->setMaxLength(5);

    //this->gih->launchConstraintDialog("MaxLength");
    //this->gih->addAcceptConstraint(mlc);
    //this->gih->addRejectConstraint(adec);

    for(int i=0; i<this->gih->getAcceptedConstraints().size(); i++)
        bts.addAcceptConstraint(this->gih->getAcceptedConstraints().at(i));
    for(int i=0; i<this->gih->getRejectedConstraints().size(); i++)
        bts.addRejectConstraint(this->gih->getRejectedConstraints().at(i));

    QVector<Path> solutions;
    Path starting=Path(this->gih->getNodes().length());
    foreach(Node* node, this->gih->getNodes())
    {
        starting.addName(node->text());
    }
    cout<<"asking solutions!"<<endl;
    bts.getSolutions(starting, &solutions);
    cout<<"solutions.size() outside is: "<<solutions.size()<<endl;
    unsigned int bestPathLength=INT_MAX;
    //if(solutions.size()!=0 || &solutions.at(0)!=NULL)
    //if(solutions.size()!=0 || solutions.size()!=1)
    if(solutions.size()!=0 && &solutions.at(0)!=NULL)
    {
        cout<<"solutions are:"<<endl;
        Path shortest=solutions.at(0);
        shortest.print();
        bestPathLength=gih->getLengthOfPath(shortest);
        for(int i=1; i<solutions.size(); i++)
        {
            Path act=solutions.at(i);
            act.print();
            unsigned int newLength=gih->getLengthOfPath(act);
            if(newLength<bestPathLength && newLength!=0)
            {
                shortest=act;
                bestPathLength=newLength;
            }
            cout<<"length of this path: "<<newLength<<endl;
        }
    }
    else
        cout<<"no solutions LOL"<<endl;
    QMessageBox::information(this, "ok, solved!", QString::number(solutions.size())+
                             " solutions, best length is:"+QString::number(bestPathLength));
}

void DiagramWindow::getDistanceSlot()
{
    NodesSelectorDialog nsd(gih, 0);
    nsd.setWindowTitle("Get distance between two nodes");
    nsd.setSwitchNodesChecked(false, false);
    nsd.setLinkExistingLabelVisible(false);
    nsd.exec();
}

void DiagramWindow::chooseConstraintSlot()
{
    ConstraintChooserDialog ccd(this->gih, this);
    ccd.exec();
}

void
DiagramWindow::getFloodingSlot()
{
    cout<<"è diventato Genetic Slot LOL"<<endl;
/*
    //just for test, going to replace it w/ a dialog
    Node* startNode=this->gih->getNodes().at(0);

    FloodingSolver fs(this->gih);
    foreach(Constraint* accepted, this->gih->getAcceptedConstraints())
        fs.addAcceptConstraint(accepted);
    foreach(Constraint* rejected, this->gih->getRejectedConstraints())
        fs.addRejectConstraint(rejected);
    Path solution=fs.getBestSolution(startNode->text(), startNode->text());
*/

    //pop:100, crossover:20, gen:50, foreign:5
    //pop:50, crossover:10, gen:60, foreign:5
    //it was: 100
    int n=this->gih->getNodes().size();
    GeneticEngine ge(25*n);
    ge.setGIH(this->gih);
    ge.setCrossover(200/*30*/);
    ge.setMutationProbability(0.01);
    ge.setPopulationDimension(1067/*100*/);
    ge.setNewIndividualsNumber(20/*5*/);
    ge.setElitismNumber(50);
    foreach(Constraint *constr, this->gih->getAcceptedConstraints())
        ge.addAcceptConstraint(constr);
    foreach(Constraint *constr, this->gih->getRejectedConstraints())
        ge.addRejectConstraint(constr);
    ge.getBestPaths();
    for(unsigned int i=0; i<10; i++)
    {
        Path p=ge.getPopulation().at(ge.getPopulationDimension()-1-i);
        p.print();
        cout<<"score of this solution is: "<<ge.getScores().at(ge.getPopulationDimension()-1-i)<<endl;
    }
    cout<<"terminata l'esecuzione"<<endl;
    QMessageBox::information(this, "Genetic Slot terminated!", "il risolutore genetico ha finito l'elaborazione");
}

void
DiagramWindow::testConstraintRespectSlot()
{
    SolutionTestingDialog std;
    std.setGIH(this->gih);
    std.scoreCalculation(false);
    std.exec();
    //fixin' issue: graph remains blue when SolutionTestingDialog is closed
    foreach(Link *link, this->gih->getLinks())
        link->setColor(Qt::darkRed);
}

void
DiagramWindow::testConstraintScoreSlot()
{
    SolutionTestingDialog std;
    std.setGIH(this->gih);
    std.scoreCalculation(true);
    std.exec();
    //fixin' issue: graph remains blue when SolutionTestingDialog is closed
    foreach(Link *link, this->gih->getLinks())
        link->setColor(Qt::darkRed);
}
