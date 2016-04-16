#include "nvmrange.h"

NvmRange::NvmRange(uint h, uint l, Nvm &nvm)
    : _range(h,l),
      _updated(false),
      _nvm(&nvm)
{
    Q_ASSERT(_range.hIndex() < nvm.size());
    registerRange(_range, _nvm);
}

NvmRange::NvmRange(const Range &range, Nvm &nvm)
    : _range(range),
      _updated(false),
      _nvm(&nvm)
{
    Q_ASSERT(_range.hIndex() < nvm.size());
    registerRange(_range, _nvm);
}

NvmRange::NvmRange(const NvmRange &other)
    : _range(0,0),
      _updated(false),
      _nvm(0)
{
    copy(other);
    registerRange(_range, _nvm);
}

void NvmRange::registerRange(const Range &range, Nvm *nvm)
{
    for (uint i = range.hIndex(); i >= range.lIndex(); --i)
        nvm->bit(i).addObserver(this);
}

void NvmRange::deRegisterRange(const Range &range, Nvm *nvm)
{
    for (unsigned int i = range.hIndex(); i >= range.lIndex(); --i)
        nvm->bit(i).removeObserver(this);
}

void NvmRange::copy(const NvmRange &other)
{
    _range = other._range;
    _nvm = other._nvm;
    _updated = other._updated;
}

NvmRange &NvmRange::operator=(const NvmRange &other)
{
    deRegisterRange(_range, _nvm);
    copy(other);
    registerRange(_range, _nvm);
    return *this;
}

NvmRange::~NvmRange()
{
    Q_ASSERT(_nvm);
    deRegisterRange(_range, _nvm);
}

void NvmRange::forwardUpdates() const
{
    if (_updated)
    {
        notify();
        _updated = false;
    }
}

void NvmRange::update()
{
    _updated = true;
}

QVector<bool> NvmRange::nvmData() const
{
    return _nvm->data(_range);
}
