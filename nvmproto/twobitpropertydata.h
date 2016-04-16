#ifndef TWOBITPROPERTYDATA_H
#define TWOBITPROPERTYDATA_H

#include "propertydata.h"

class TwoBitPropertyData : public PropertyData
{
    enum State { State0, State1, State2, State3 };

public:
    TwoBitPropertyData(const QString &name, NvmRange &range);
    void update();
    State currentState() const { return _state; }

protected:
    State _state;
};

#endif // TWOBITPROPERTYDATA_H
