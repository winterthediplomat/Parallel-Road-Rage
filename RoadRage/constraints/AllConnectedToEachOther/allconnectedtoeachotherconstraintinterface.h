#ifndef ALLCONNECTEDTOEACHOTHERCONSTRAINTINTERFACE_H
#define ALLCONNECTEDTOEACHOTHERCONSTRAINTINTERFACE_H

#include "constraintinterface.h"
#include "constraints/AllConnectedToEachOther/allconnectedtoeachother.h"

class AllConnectedToEachOtherConstraintInterface : public ConstraintInterface
{
public:
    AllConnectedToEachOtherConstraintInterface(GraphInformationHandler *gih);

    virtual bool hasUI();
    virtual AllConnectedToEachOther* getConstraintObj();
    virtual ConstraintDialog* getDialog();
};

#endif // ALLCONNECTEDTOEACHOTHERCONSTRAINTINTERFACE_H
