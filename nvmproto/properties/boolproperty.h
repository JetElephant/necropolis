#ifndef BOOLPROPERTY_H
#define BOOLPROPERTY_H

#include "property.h"
#include "onebitpropertydata.h"

#include <QStringList>
#include <QMap>

class BoolProperty : public Property
{
public:
    BoolProperty(const QString &name, OneBitPropertyData &data);
    bool currentState() const { return _state; }
    QString currentStateName() const { return _states.value(_data.currentState()); }
    QStringList states() const { return _states.values(); }
    void update();
    bool setState(OneBitPropertyData::State state);
    bool setState(const QString &stateName);

private:
    bool _state;
    OneBitPropertyData &_data;
    QMap<OneBitPropertyData::State, QString> _states;
};

#endif // BOOLPROPERTY_H
