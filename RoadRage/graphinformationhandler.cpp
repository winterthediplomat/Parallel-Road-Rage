#include "graphinformationhandler.h"
#include "QFile"
#include "QTextStream"
#include "iostream"
#include "constraintpositionchooserdialog.h"
#include "QMessageBox"
using namespace std;

//################ CONSTRAINTS #####################
//#include "constraints/maxlengthconstraint.h"
#include "constraints/AllDifferentElements/alldifferentelementsconstraintinterface.h"
#include "constraints/MaxLength/maxlengthconstraintinterface.h"
#include "constraints/AllConnectedToEachOther/allconnectedtoeachotherconstraintinterface.h"
#include "constraints/LastPointConnectedToFirst/lastpointconnectedtofirstconstraintinterface.h"
//##################################################

//################ SOLVERS #########################
#include "solvers/backtracking/btsolver.h"
//##################################################

GraphInformationHandler::GraphInformationHandler()
{
    //this->headNodeInfo=NULL;
    cout<<"hello by GIH!"<<endl;
    //this->links=QList<Link*>();
    //this->nodes=QList<Node*>();
    cout<<"this->nodes address: "<<&this->nodes<<endl;
    this->linksDescriptors=QVector<LinksDescriptor*>();

    this->acceptedConstraints=QVector<Constraint*>();
    this->rejectedConstraints=QVector<Constraint*>();


    //########## constraintNames initialization ########
    this->constraintNames=new QMap<QString, ConstraintInterface*>;
    this->constraintNames->insert("AllDifferentElements",
                                  new AllDifferentElementsConstraintInterface(this));
    this->constraintNames->insert("MaxLength",
                                  new MaxLengthConstraintInterface(this));
    this->constraintNames->insert("AllConnectedToEachOther",
                                  new AllConnectedToEachOtherConstraintInterface(this));
    this->constraintNames->insert("LastPointConnectedToFirst",
                                  new LastPointConnectedToFirstConstraintInterface(this));
    //##################################################

    //########## solverNames initialization ############
    this->solverNames=new QMap<QString, Solver*>;
    this->solverNames->insert("BacktrackingTSPSolver",
                              new BTSolver());
    //##################################################
}

bool GraphInformationHandler::addLink(Link *newLink)
{
    cout<<"entered in GraphInformationHandler::addLink"<<endl;
    foreach(Link *actual, this->links)
    {
        if ( (actual->fromNode()==newLink->fromNode()) and
                (actual->toNode()==newLink->toNode()) )
            return false;
    }
    this->links.append(newLink);
    return true;
}

bool GraphInformationHandler::removeLink(Link *oldLink)
{
    int index=this->links.indexOf(oldLink);
    cout<<"GIH::removeLink - index of "<<oldLink<<" == "<<index<<endl;
    if(index!=-1)  //found
    {
        cout<<"found!"<<endl;
        this->links.removeAt(index);
        return true;
    }
    cout<<"not found D:"<<endl;
    return false;
}

bool GraphInformationHandler::updateLink(Link *linkToUpdate, unsigned int newDistance)
{
    Link* oldLink;
    foreach(Link *candidate, links)
        if (candidate==linkToUpdate)
            oldLink=candidate;

    linkToUpdate->setDistance(newDistance);
    linkToUpdate->setDescription(
            QString("%1->%2=%3").arg(linkToUpdate->fromNode()->text(), linkToUpdate->toNode()->text(), QString::number(newDistance))
            );
    this->updateLinkTrack();
    return oldLink->distance()==linkToUpdate->distance();
}

void GraphInformationHandler::updateLink(Node *fromNode, Node *toNode, unsigned int newDistance)
{

    foreach(Link *candidate, links)
        if (candidate->fromNode()==fromNode and candidate->toNode()==toNode)
        {
            candidate->setDistance(newDistance);
            candidate->setDescription(
                    QString("%1->%2=%3").arg(fromNode->text(), toNode->text(), QString::number(newDistance))
                    );
        }
    this->updateLinkTrack();
}

void GraphInformationHandler::execDijkstra(unsigned int startNodeNum, unsigned int endNodeNum,
                                           QList<unsigned int> &distance, QList<int> &previous,
                                           QList<bool> &visited)
{
    //this function executes the Dijkstra algorithm on graphs
    //this function has five parameters
    //startNodeNum (IN): int, the number of the start node
    //endNodeNum (IN): int, the number of the end node
    //distance (OUT): QList<int>, it will contain distances of all nodes in the graph
    //previous (OUT): QList<int>, it will contain previous nodes of all nodes in the graph
    //visited (OUT): QList<bool>, it will contain "visited" flag of related node
    const unsigned int NODE_NO=this->nodes.count();
    unsigned int matrix[NODE_NO][NODE_NO];
    unsigned int INFINITO=2147483647;
    //carico la matrice
    for(unsigned int i=0; i<NODE_NO; i++)
    {
        for(unsigned int j=0; j<NODE_NO; j++)
        {
            Link* link=this->getTheLinkByNodes(this->getNodeByIndex(i), this->getNodeByIndex(j));
            if(link)
            {
                matrix[i][j]=link->distance();
            }
            else
            {
                matrix[i][j]=INFINITO;
            }
        }
        visited.append(false);
        previous.append(-1);
        distance.append(INFINITO);
    }
    cout<<"startNodeNum=="<<startNodeNum<<"\tendNodeNum=="<<endNodeNum<<endl;
    cout<<"caricata la matrice!"<<endl;
    distance[startNodeNum]=0;
    unsigned int min_length, actualNodeNum;
    bool arrivedAtEnd=false;
    while(!arrivedAtEnd)
    {
        min_length=INFINITO;
        for(unsigned int candidateNodeNum=0; candidateNodeNum<NODE_NO; candidateNodeNum++)
        {
            if(!visited[candidateNodeNum] && distance[candidateNodeNum]<=min_length)
            {
                actualNodeNum=candidateNodeNum;
                min_length=distance[actualNodeNum];
            }
        }
        visited[actualNodeNum]=true;
        if ((min_length==INFINITO) || (actualNodeNum==endNodeNum))
        {
            arrivedAtEnd=true;
        }
        else
        {
            for(unsigned int i=0; i<NODE_NO; i++)
            {
                if(matrix[actualNodeNum][i] && distance[i]>distance[actualNodeNum]+matrix[actualNodeNum][i])
                {
                    distance[i]=distance[actualNodeNum]+matrix[actualNodeNum][i];
                    previous[i]=actualNodeNum;
                }
            }
        }
    }
}

Node* GraphInformationHandler::getNodeByIndex(int index)
{
    //return the node at the given index
    return this->nodes.at(index);  
}

void GraphInformationHandler::generateReport()
{
    /*
    //this function generates a CSV file
    FILE *csvFile=fopen("the_file.csv", "w");
    if(csvFile!=NULL)
    {
        foreach (Link *currentLink, this->links)
        {
            //qui dovrei scrivere un file csv.
            fprintf(csvFile,"%s,%s,%i\n",
                    currentLink->fromNode()->text().toStdString().c_str(),
                    currentLink->toNode()->text().toStdString().c_str(),
                    currentLink->distance());
        }
        fclose(csvFile);
        //delete csvFile;
     }
    fclose(csvFile);
    */
    //this function generates an HTML file
    unsigned int INFINITO=2147483647;
    QFile file("outD.html");
    file.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream report(&file);
    

    QList<int> prev;
    QList<unsigned int> distance;
    QList<bool> visited;
    Node *startNode, *endNode;
    report<<"<html>"<<endl;
    report<<"<head>"<<endl;
    report<<"   <!-- corpo di una pagina html, questo è il report! -->"<<endl;
    report<<"   <!-- \"notch servo, aggiusta i bug!\" (cit. Chiunque su Minecraft) -->"<<endl;
    report<<"   <script>"<<endl;
    report<<"   infoMap={};"<<endl;
    report<<"   function modifica(idSezione)"<<endl;
    report<<"   {"<<endl;
    report<<"       var sezione=document.getElementById(idSezione);"<<endl;
    report<<"       var modificatoreSezione=document.getElementById(idSezione+'_modifier');"<<endl;
    report<<"       if(sezione.innerHTML==\"hidden\")"<<endl;
    report<<"       {"<<endl;
    report<<"           sezione.innerHTML=infoMap[idSezione];"<<endl;
    report<<"           modificatoreSezione.innerHTML='hide';"<<endl;
    report<<"       }"<<endl;
    report<<"       else"<<endl;
    report<<"       {"<<endl;
    report<<"           infoMap[idSezione]=sezione.innerHTML;"<<endl;
    report<<"           sezione.innerHTML=\"hidden\";"<<endl;
    report<<"           modificatoreSezione.innerHTML='show';"<<endl;
    report<<"       }"<<endl;
    report<<"   }"<<endl;
    report<<"   </script>"<<endl;
    report<<"</head>"<<endl;
    report<<"<body>"<<endl;
    for(int startNodeNum=0; startNodeNum<this->getNodes().count(); startNodeNum++)
    {
        startNode=this->getNodeByIndex(startNodeNum);
        report<<QString("      <div id='%1'>").arg(
                startNode->text())<<endl;
        for(int endNodeNum=0; endNodeNum<this->getNodes().count(); endNodeNum++)
        {
            prev=QList<int>();
            distance=QList<unsigned int>();
            visited=QList<bool>();

            if(startNodeNum!=endNodeNum)
            {
                this->execDijkstra(startNodeNum, endNodeNum, distance, prev, visited);
                endNode=this->getNodeByIndex(endNodeNum);
                if(distance[endNodeNum]==INFINITO)
                {
                    report<<QString("       <font color='red'><p>does not exist a way to go from node %1 to node %2</p></font>").arg(
                            startNode->text(), endNode->text())<<endl;
                }
                else
                {
                    report<<QString("       <font color='green'><p>the distance from node %1 to node %2 is %3</p></font>").arg(
                            startNode->text(), endNode->text(), QString::number(distance[endNodeNum]))<<endl;
                    QString path("");
                    unsigned int actualNodeNum=endNodeNum;
                    if(prev[endNodeNum]==startNodeNum)
                    {
                        path=QString("<font color='yellow'>")+endNode->text()+QString("</font>");
                    }
                    while(prev[actualNodeNum]!=startNodeNum)
                    {
                        if (actualNodeNum!=endNodeNum)
                            path+=QString("->");
                        path+=QString("<font color='yellow'>")+this->getNodeByIndex(actualNodeNum)->text()+QString(+"</font>");
                        actualNodeNum=prev[actualNodeNum];
                    }
                    path+=QString("-><font color='yellow'>")+startNode->text()+QString("</font>");
                    report<<QString("<p>the path is: %1</p>").arg(path)<<endl;

                }
            }
        }
        report<<"<br />"<<endl<<"</div>"<<endl;
        report<<QString("      <a id='%1_modifier' href='javascript:modifica(\"%1\");'>hide</a>").arg(
                startNode->text())<<endl;
    }
    report<<"</body>"<<endl;
    report<<"</html>"<<endl;

    file.close();
}


QList<Link*>
GraphInformationHandler::getLinksByNodes(Node *first, Node *second)
{
    QList<Link* > the_links;
    foreach(Link *candidateLink, this->links)
    {
        if ((candidateLink->fromNode()==first and
                candidateLink->toNode()==second) or
            (candidateLink->fromNode()==second and
                candidateLink->toNode()==first)
            )
        {
            the_links.append(candidateLink);
        }
    }
    return the_links;
}

Link*
GraphInformationHandler::getTheLinkByNodes(Node* fromNode, Node* toNode)
{
    foreach(Link* candidate, this->links)
    {
        if ((candidate->fromNode()==fromNode) and
              (candidate->toNode()==toNode))
            return candidate;
    }
    return NULL;
}

QList<Link *> GraphInformationHandler::getLinks()
{return links;}

void GraphInformationHandler::deleteAllLinks()
{
    foreach(Link *link, links)
    {
        delete link->fromNode();
        delete link->toNode();
        delete link;
    }
}

void GraphInformationHandler::addNode(Node* newNode)
{
    //cout<<"added a node "<<&newNode<<endl;
    cout<<"added a node "<<newNode<<endl;
    this->nodes.append(newNode);
}

void GraphInformationHandler::removeNode(Node *oldNode)
{
    int indexOfOldNode=this->nodes.indexOf(oldNode);
    if(indexOfOldNode>=0)
    {
        cout<<"the node "<<oldNode<<"should be deleted here, unless it crashes D:"<<endl;
        delete oldNode;
        cout<<"the node is no longer usable"<<endl;
        this->nodes.removeAt(indexOfOldNode);
    }
}

Node* GraphInformationHandler::getNodeByText(QString searchedText)
{
    //cout<<"&GraphInformationHandler->nodes="<<&this->nodes<<endl;
    //cout<<"GraphInformationHandler=="<<this<<endl;
    //if(&this->nodes==NULL)
    //    cout<<"nodes is null"<<endl;
    /*foreach(Node *manchurian_candidate, this->nodes) //lol Node* name :D
    {
        cout<<searchedText.toStdString()<<"\t"<<(manchurian_candidate==NULL)<<endl;
        if(manchurian_candidate->text()==searchedText)
            return manchurian_candidate;
    }*/
    for(unsigned i=0; i<this->nodes.size(); i++)
    {
        //cout<<searchedText.toStdString()<<"\t"<<(this->nodes.at(i)==NULL)<<endl;
        if(this->nodes.at(i)->text()==searchedText)
            return this->nodes.at(i);
    }
    return NULL;
}

QList<Node*> GraphInformationHandler::getNodes()
{
    return this->nodes;
}


void GraphInformationHandler::updateLinkTrack()
{
    //questa funzione viene richiamata quando si
    //devono spostare due nodi (switchNodes)
    //non fa altro che aggiornare le tracce dei
    //collegamenti (Link è sottoclasse di QGraphicsLineItem)
    cout<<"entered in GIH::updateLinkTrack()"<<endl;
    foreach(Link *actual_link, this->links)
    {
        actual_link->trackNodes();
    }

    foreach(LinksDescriptor* ld, this->linksDescriptors)
    {
        cout<<"updating linksdescriptors"<<endl;
        QPair<qreal, qreal>midPoint=ld->getLinks().first->getMidPoint();
        ld->getDescription()->setX(midPoint.first);
        ld->getDescription()->setY(midPoint.second);
        ld->setDescriptionText(
                ld->getLinks().first->description()+QString("\n")+ld->getLinks().second->description());
        cout<<ld->getDescription()->x()<<endl;
        cout<<ld->getDescription()->y()<<endl;
        cout<<"lolasd!"<<endl;
    }
}

void GraphInformationHandler::addLinksDescriptor(LinksDescriptor *newLinksDescriptor)
{
    this->linksDescriptors.append(newLinksDescriptor);
}

LinksDescriptor* GraphInformationHandler::getLinksDescriptorByLinks(Link *first, Link *second)
{
    foreach(LinksDescriptor* descriptor, this->linksDescriptors)
    {
        if ((descriptor->getLinks().first==first) and
            (descriptor->getLinks().second==second))
            return descriptor;
    }
    return NULL;
}

void GraphInformationHandler::addAcceptConstraint(Constraint *newConstraint)
{
    this->acceptedConstraints.append(newConstraint);
    cout<<"added a new accept constraint: ";
    newConstraint->printName();
}

void GraphInformationHandler::addRejectConstraint(Constraint *newConstraint)
{
    this->rejectedConstraints.append(newConstraint);
    cout<<"added a new reject constraint: ";
    newConstraint->printName();
}

Constraint* GraphInformationHandler::createConstraint(QString constraintName)
{
    return this->constraintNames->value(constraintName)->getConstraintObj();
}

void GraphInformationHandler::createConstraint(QString constraintName, Constraint *constraintObj)
{
    constraintObj=this->constraintNames->value(constraintName)->getConstraintObj();
}

QDialog* GraphInformationHandler::createConstraintDialog(QString constraintName)
{
    return this->constraintNames->value(constraintName)->getDialog();
}

void GraphInformationHandler::removeRejectedConstraint(Constraint *oldConstraint)
{
    int position=0;
    foreach(Constraint* constr, this->rejectedConstraints)
        if(constr!=oldConstraint)
            position++;

    this->rejectedConstraints.remove(position);
    delete oldConstraint;
}

void GraphInformationHandler::removeAcceptedConstraint(Constraint *oldConstraint)
{
    int position=0;
    foreach(Constraint* constr, this->acceptedConstraints)
        if(constr!=oldConstraint)
            position++;

    this->acceptedConstraints.remove(position);
    delete oldConstraint;
}



QVector<QString> GraphInformationHandler::getConstraintNamesList()
{
    return this->constraintNames->keys().toVector();
}

ConstraintInterface* GraphInformationHandler::getConstraintInterface(QString constraintName)
{
    return this->constraintNames->value(constraintName);
}


QVector<Constraint*> GraphInformationHandler::getAcceptedConstraints()
{
    return this->acceptedConstraints;
}

QVector<Constraint*> GraphInformationHandler::getRejectedConstraints()
{
    return this->rejectedConstraints;
}

void GraphInformationHandler::launchConstraintDialog(QString constraintName)
{
    /*
      I need this GIH method to launch the right constraint dialog
      'cause I can't rely on GIH::getConstraintInterface::getDialog.
      GIH::getConstraintDialog returns a Constraint object, I need a
      Constraint subclass object
    */
    //if(this->constraintNames->value(constraintName)->hasUI())
    if(this->constraintNames->value(constraintName)->getDialog()!=NULL)
        this->constraintNames->value(constraintName)->getDialog()->exec();
    else
    {
        /*
          we need to ask user if new constraint is a Accept constraint
          or a Reject one.
        */
        ConstraintPositionChooserDialog cpcd;
        Constraint* constraintObj=this->createConstraint(constraintName);
        //if(constraintObj->needsGIH())
        //    constraintObj->setGIH(this);
        cout<<"just for control, gih obj address is: "<<this<<endl;
        if(cpcd.exec()==QDialog::Accepted)
        {
            if(cpcd.isAccept)
                this->addAcceptConstraint(constraintObj);
            else
                this->addRejectConstraint(constraintObj);
            QMessageBox::information(0, "added a constraint",
                                     QString("added new constraint %1").arg(constraintName));
        }
    }
}

unsigned int
GraphInformationHandler::getLengthOfPath(Path examinedPath)
{
    /*
      TODO: check examinedPath has some points that are not
      connected and replace length with Dijkstra calculated distance
    */
    unsigned int lengthOfPath=0;
    Node *start, *end;
    Link *link;
    for(int i=0; i<examinedPath.getPath().size()-1; i++)
    {
        start=this->getNodeByText(examinedPath.namesRelatedToPath().at(i));
        end=this->getNodeByText(examinedPath.namesRelatedToPath().at(i+1));
        link=this->getTheLinkByNodes(start, end);

        if(!link)
            return INT_MAX;
        lengthOfPath+=link->distance();
    }
    return lengthOfPath;
}
