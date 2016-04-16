#include "twobitpropertydata.h"

TwoBitPropertyData::TwoBitPropertyData(const QString &name, NvmRange &range)
    : PropertyData(name, range),
      _state(State0)
{
    Q_ASSERT(range.size() == 2); //two-bit check
}

void TwoBitPropertyData::update()
{
    qDebug("Property updated!");
    _state = static_cast<State>(processNvmData(_rangeCtrl.nvmData()));
}
