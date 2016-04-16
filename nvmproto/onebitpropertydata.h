#ifndef ONEBITPROPERTYDATA_H
#define ONEBITPROPERTYDATA_H

#include "propertydata.h"

class OneBitPropertyData : public PropertyData
{
public:
    enum State { Disabled, Enabled };

    OneBitPropertyData(const QString &name, NvmRange &range);
    void update();
    State currentState() const { return _state; }
    void setState(State state);

protected:
    State _state;
};

#endif // ONEBITPROPERTYDATA_H
