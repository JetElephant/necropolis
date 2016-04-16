#ifndef NVM_H
#define NVM_H

#include "observable.h"
#include <QVector>
#include "nvmbit.h"
#include "range.h"

#define defaultNvmSize 20

class Nvm : public Observable
{
public:
    Nvm(int size);
    void setBit(uint id, bool value = true);
    void setRange(const Range &range, const QVector<bool> &values);
    NvmBit& bit(uint id);
    const NvmBit& bit(uint id) const;
    uint size() const { return _size; }
    QVector<bool> data(const Range &range) const;

private:
    QVector<NvmBit*> _data;
    uint _size;
};

#endif // NVM_H
