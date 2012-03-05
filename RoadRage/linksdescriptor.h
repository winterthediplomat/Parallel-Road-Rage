#ifndef LINKSDESCRIPTOR_H
#define LINKSDESCRIPTOR_H

#include "link.h"

class LinksDescriptor
{
public:
    LinksDescriptor(Link* first, Link* second, QGraphicsTextItem* description=NULL);
    ~LinksDescriptor();

    void setDescriptionText(QString descriptionText);
    QString getDescriptionText();
    void setDescription(QGraphicsTextItem* newDescription);
    QGraphicsTextItem* getDescription();

    QPair<Link*, Link*> getLinks();


private:
    Link* firstLink;
    Link* secondLink;
    QGraphicsTextItem* description;
};

#endif // LINKSDESCRIPTOR_H
