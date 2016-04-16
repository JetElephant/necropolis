#include "boolproperty.h"

BoolProperty::BoolProperty(const QString &name, OneBitPropertyData &data)
    : Property(name),
      _state(false),
      _data(data)
{
    _data.addObserver(this);
    _states[OneBitPropertyData::Enabled] = "Enabled";
    _states[OneBitPropertyData::Disabled] = "Disabled";
}

void BoolProperty::update()
{
    qDebug("Property updated!");
    _state = (_data.currentState() == OneBitPropertyData::Enabled);
}

bool BoolProperty::setState(OneBitPropertyData::State state)
{
    _data.
}

bool BoolProperty::setState(const QString &stateName)
{
    return false;
}
