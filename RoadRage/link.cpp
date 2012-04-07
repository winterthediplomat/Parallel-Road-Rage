#include <QtGui>

#include "link.h"
#include "node.h"


Link::Link(Node *fromNode, Node *toNode)
{
    myFromNode = fromNode;
    myToNode = toNode;

    myFromNode->addLink(this);
    myToNode->addLink(this);

    this->theDistance=2147483647;

    this->theDescription=new QString("");
    setFlags(QGraphicsItem::ItemIsSelectable);
    setZValue(-1);

    setColor(Qt::darkRed);
    trackNodes();
}

Link::Link(Link *aLink)
{
    myFromNode=aLink->fromNode();
    myToNode=aLink->toNode();

    myFromNode->addLink(this);
    myToNode->addLink(this);

    this->theDistance=2147483647;
    this->theDescription=new QString(aLink->description());


    setFlags(QGraphicsItem::ItemIsSelectable);
    setZValue(-1);

    setColor(Qt::darkRed);
    trackNodes();
}


Link::~Link()
{
    myFromNode->removeLink(this);
    myToNode->removeLink(this);
    delete theDescription;
}

Node *Link::fromNode() const
{
    return myFromNode;
}

Node *Link::toNode() const
{
    return myToNode;
}

void Link::setColor(const QColor &color)
{
    setPen(QPen(color, 1.0));
}

QColor Link::color() const
{
    return pen().color();
}

void Link::trackNodes()
{
    setLine(QLineF(myFromNode->pos(), myToNode->pos()));
}

unsigned int Link::distance() const
{return this->theDistance;}

void Link::setDistance(unsigned int newDistance)
{
    this->theDistance=newDistance;
    setDescription(QString("%1->%2=%3").arg(fromNode()->text(),
          toNode()->text(),
          QString::number(distance())));
}


void Link::setDescription(QString description)
{this->theDescription=new QString(description);}

QString Link::description()
{return *(this->theDescription);}


QPair<qreal, qreal> Link::getMidPoint()
{
    //this function calculates the mid point of
    //the link, using position of nodes
    //math rulez, bro! :D
    qreal minX=myFromNode->x()<myToNode->x()?myFromNode->x():myToNode->x();
    qreal maxX=myFromNode->x()<myToNode->x()?myToNode->x():myFromNode()->x();

    qreal minY=myFromNode->y()<myToNode->y()?myFromNode->y():myToNode->y();
    qreal maxY=myFromNode->y()<myToNode->y()?myToNode->y():myFromNode()->y();

    //qreal midX=((myToNode()->x()-myFromNode()->x())/2)+minX;
    //qreal midY=((myToNode()->x()-myFromNode()->y())/2)+minY;
    qreal midX=(maxX+minX)<<1; //n/2 (integer division) == n<<1
    qreal midY=(maxY+minY)<<1;
    return QPair<qreal, qreal>(midX, midY);
}
