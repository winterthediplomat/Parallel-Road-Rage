#include "linksdescriptor.h"

LinksDescriptor::LinksDescriptor(Link *first, Link *second, QGraphicsTextItem *description)
{
    this->firstLink=first;
    this->secondLink=second;
    this->description=description;
}

LinksDescriptor::~LinksDescriptor()
{
    delete description;
}


QGraphicsTextItem* LinksDescriptor::getDescription()
{return this->description;}

void LinksDescriptor::setDescription(QGraphicsTextItem *newDescription)
{this->description=newDescription;}

QString LinksDescriptor::getDescriptionText()
{return this->description->toPlainText();}

void LinksDescriptor::setDescriptionText(QString descriptionText)
{this->description->setPlainText(descriptionText);}

QPair<Link*, Link*> LinksDescriptor::getLinks()
{return QPair<Link*, Link*>(this->firstLink, this->secondLink);}
