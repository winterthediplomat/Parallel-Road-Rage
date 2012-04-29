#ifndef DIAGRAMWINDOW_H
#define DIAGRAMWINDOW_H

#include <QMainWindow>
#include <QPair>
#include "graphinformationhandler.h"
#include "linksdescriptor.h"

class QAction;
class QGraphicsItem;
class QGraphicsScene;
class QGraphicsView;
class Link;
class Node;

class DiagramWindow : public QMainWindow
{
    Q_OBJECT

public:
    DiagramWindow();
    //GraphInformationHandler* getGIH();

private slots:
    void addNode();
    void addLink();
    void del(QList<QGraphicsItem *> items=QList<QGraphicsItem*>());
    void cut();
    void copy();
    void paste();
    void bringToFront();
    void sendToBack();
    void properties();
    void updateActions();

    //added slots
    void generateReport();
    void updateLinks();
    void openGraph();
    void saveGraph();
    void selectNodes();
    void switchNodesSlot();
    void getDistanceSlot();

    void getBacktrackingTSPSlot();
    //void getDijkstraSlot();
    void getFloodingSlot();
    void chooseConstraintSlot();
    //constraint slots
    //void setConstraintOnNodeSlot();
    void testConstraintRespectSlot();
    void testConstraintScoreSlot();

private:
    typedef QPair<Node *, Node *> NodePair;

    void createActions();
    void createMenus();
    void createToolBars();
    void setZValue(int z);
    void setupNode(Node *node);
    Node *selectedNode() const;
    Link *selectedLink() const;
    NodePair selectedNodePair() const;

    //added function
    void modified(const QString *givenFileName=0);
    void switchNodes(Node *firstNode, Node *secondNode);

    QMenu *fileMenu;
    QMenu *editMenu;    
    QToolBar *editToolBar;
    QAction *exitAction;
    QAction *addNodeAction;
    QAction *addLinkAction;
    QAction *deleteAction;
    QAction *cutAction;
    QAction *copyAction;
    QAction *pasteAction;
    QAction *bringToFrontAction;
    QAction *sendToBackAction;
    QAction *propertiesAction;

    //added QToolBar
    QToolBar *utilityToolBar;

    //added QMenus
    //QMenu *constraintMenu;
    QMenu *solverMenu;
    //QAction *setConstraintOnNodeAction;
    QMenu *testMenu;

    //added QActions
    QAction *generateReportAction;
    QAction *updateLinkAction;
    QAction *openGraphAction;
    QAction *saveGraphAction;
    QAction *selectNodesAction;
    QAction *switchNodesAction;
    QAction *getDistanceAction;

    QAction* getBacktrackingTSPAction;
    //QAction* getDijkstraAction;
    QAction* getFloodingAction;
    QAction* chooseConstraintAction;

    QAction* testConstraintRespect;
    QAction* testConstraintScore;

    QGraphicsScene *scene;
    QGraphicsView *view;

    int minZ;
    int maxZ;
    int seqNumber;

    //added things
    GraphInformationHandler *gih;
    QString currentFile;
    bool isGraphModified;
    //QList<LinksDescriptor*> linkDescriptions;
};

#endif
