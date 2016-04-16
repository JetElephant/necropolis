#include "nvmbit.h"

#include <QDebug>

NvmBit::NvmBit()
    : _data(false)
{
//    qDebug(Q_FUNC_INFO);
}

NvmBit::NvmBit(bool value)
    : _data(false)
{
    setData(value);
//    qDebug(Q_FUNC_INFO);
}

NvmBit::NvmBit(const NvmBit &other)
    : _data(false)
{
    setData(other);
    qDebug(Q_FUNC_INFO);
}

void NvmBit::setData(bool value)
{
    qDebug("Nvm Bit set!");
//    const bool &ptr = _data;
//    const_cast<bool&>(ptr) = value;
    _data = value;
    notify();
}

NvmBit &NvmBit::operator=(bool value)
{
    setData(value);
    return *this;
}

NvmBit &NvmBit::operator=(NvmBit &value)
{
    setData(value);
    return *this;
}
