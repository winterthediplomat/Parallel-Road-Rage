#ifndef STARTFROMPOINT_H
#define STARTFROMPOINT_H

#include "constraint.h"

class StartFromPointConstraint : public Constraint
{
private:
    unsigned int firstPoint;
public:
    StartFromPointConstraint();

    void setFirstPoint(const unsigned int firstPoint);
    unsigned int getFirstPoint();

    void printName();
    bool isRespected(Path candidate);
    QString generateJSON();
};

#endif // STARTFROMPOINT_H
