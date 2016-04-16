#include "propertydata.h"

PropertyData::PropertyData(const QString &name, NvmRange &range)
    : _rangeCtrl(range),
      _name(name)
{
    _rangeCtrl.addObserver(this);
}

PropertyData::~PropertyData()
{
    _rangeCtrl.removeObserver(this);
}

uint PropertyData::processNvmData(const QVector<bool> data) const
{
    uint res = 0;
    foreach(bool value, data)
    {
        res = res << 1;
        res |= (value ? 1 : 0);
    }
    return res;
}

