#ifndef NVMBIT_H
#define NVMBIT_H

#include "observable.h"

class NvmBit : public Observable
{
public:
    NvmBit();
    NvmBit(bool value);
    NvmBit(const NvmBit &other);
    operator bool() const { return _data; }
    void setData(bool value);
    NvmBit& operator=(bool value);
    NvmBit& operator=(NvmBit &value);

private:
    bool _data;
};

#endif // NVMBIT_H
