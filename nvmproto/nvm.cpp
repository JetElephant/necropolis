#include "nvm.h"

Nvm::Nvm(int size)
    : _data(size),
      _size(static_cast<uint>(size))
{
    Q_ASSERT(size > 0);
    for (uint i = 0; i < _size; ++i)
        _data[static_cast<int>(i)] = new NvmBit;
}

void Nvm::setBit(uint id, bool value)
{
    Q_ASSERT(id < _size);
    *(_data[static_cast<int>(id)]) = value; //makes a copy?
//    _data.at(id).setData(value);
    notify();
}

void Nvm::setRange(const Range &range, const QVector<bool> &values)
{
    for (uint i = 0; i < range.size(); ++i)
        *(_data.at(static_cast<int>(range.lIndex() + i))) = values[static_cast<int>(i)];
    notify();
}

NvmBit &Nvm::bit(uint id)
{
    Q_ASSERT(id < _size);
    return *(_data.at(static_cast<int>(id)));
}

const NvmBit &Nvm::bit(uint id) const
{
    Q_ASSERT(id < _size);
    return *(_data.at(static_cast<int>(id)));
}

QVector<bool> Nvm::data(const Range &range) const
{
    QVector<bool> res;
    for (uint i = range.hIndex(); i >= range.lIndex(); --i)
        res.append(bit(i));
    return res;
}
