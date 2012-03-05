#ifndef LINK_H
#define LINK_H

#include <QGraphicsLineItem>

class Node;


class Link : public QGraphicsLineItem
{

public:
    Link(Node *fromNode, Node *toNode);
    Link(Link* aLink);
    ~Link();

    Node *fromNode() const;
    Node *toNode() const;

    void setColor(const QColor &color);
    QColor color() const;

    void setDistance(unsigned int newDistance);
    unsigned int distance() const;
    void setDescription(QString description);
    QString description();
    void trackNodes();
    QPair<qreal, qreal> getMidPoint();


private:
    Node *myFromNode;
    Node *myToNode;
    unsigned int theDistance;
    QString *theDescription;
};

#endif
