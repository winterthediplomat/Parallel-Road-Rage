#ifndef GRAPHINFORMATIONHANDLER_H
#define GRAPHINFORMATIONHANDLER_H
//#include <QList>
#include <QList>
#include <stdio.h>
#include "link.h"
#include "node.h"
#include <string>
#include "linksdescriptor.h"

#include "constraintinterface.h"
#include "solverinterface.h"

/*
struct NodeInfo
{
    Node *node;
    unsigned int number;
    NodeInfo *next;
};
*/


class GraphInformationHandler
{
public:
    GraphInformationHandler();
    bool addLink(Link *newLink);
    bool removeLink(Link *oldLink);
    bool updateLink(Link *linkToUpdate, unsigned int newDistance);
    void updateLink(Node *fromNode, Node *toNode, unsigned int newDistance);
    void generateReport();
    QList<Link*> getLinksByNodes(Node *first, Node *second);
    QList<Link*> getLinks();
    void deleteAllLinks();
    void addNode(Node *newNode);
    void removeNode(Node *oldNode);
    QList<Node*> getNodes();
    Node* getNodeByText(QString searchedText);
    void execDijkstra(unsigned int startNodeNum,
                      unsigned int endNodeNum,
                 QList<unsigned int> &distance,
                 QList<int> &previous,
                 QList<bool> &visited
                 );
    Node* getNodeByIndex(int index);
    Link* getTheLinkByNodes(Node* fromNode, Node* toNode);
    void updateLinkTrack();

    void addLinksDescriptor(LinksDescriptor* newLinksDescriptor);
    LinksDescriptor* getLinksDescriptorByLinks(Link* first, Link* second);

    //constraint management
    void addAcceptConstraint(Constraint* newConstraint);
    void addRejectConstraint(Constraint* newConstraint);
    /*
        you have to pass a new temporary object
        that will be compared through Constraint::isEqualTo method
    */
    void removeAcceptedConstraint(Constraint* oldConstraint);
    void removeRejectedConstraint(Constraint* oldConstraint);

    Constraint* createConstraint(QString constraintName);
    QDialog* createConstraintDialog(QString constraintName);
    ConstraintInterface* getConstraintInterface(QString constraintName);
    QVector<QString> getConstraintNamesList();
    void createConstraint(QString constraintName, Constraint* constraintObj);

    QVector<Constraint*> getAcceptedConstraints();
    QVector<Constraint*> getRejectedConstraints();

    void launchConstraintDialog(QString constraintName);
    void launchSolverDialog(QString solverName);

    unsigned int getLengthOfPath(Path examinedPath);

private:
    QList<Link *> links;
    QList<Node *> nodes;
    //QVector<Node *> nodes;
    QVector<LinksDescriptor*> linksDescriptors;

    QVector<Constraint*> acceptedConstraints;
    QVector<Constraint*> rejectedConstraints;

    QMap<QString, ConstraintInterface*> *constraintNames;
    QMap<QString, SolverInterface*> *solverNames;
    //QVector<Solver*> solvers;
    //NodeInfo *headNodeInfo;
    //NodeInfo *tailNodeInfo;
    //bool *visited;
    //unsigned int *distance;
    //unsigned int *previous;



};

#endif // GRAPHINFORMATIONHANDLER_H
