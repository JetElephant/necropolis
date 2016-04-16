#include "onebitpropertydata.h"

OneBitPropertyData::OneBitPropertyData(const QString &name, NvmRange &rangeCtl)
    : PropertyData(name, rangeCtl),
      _state(Disabled)
{
    Q_ASSERT(rangeCtl.range().size() == 1); //one-bit check
}

void OneBitPropertyData::update()
{
    //better acces method
//    _state = _range.nvm()->bit(_range.high()) ? Enabled : Disabled;
    _state = static_cast<State>(processNvmData(_rangeCtrl.nvmData()));
    qDebug("Property updated!");
}

void OneBitPropertyData::setState(OneBitPropertyData::State state)
{
    _state
}

