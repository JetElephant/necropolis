#ifndef NVMRANGE_H
#define NVMRANGE_H

#include <QSet>
#include <observable.h>

#include "nvm.h"
#include "nvmbit.h"
#include "range.h"

class NvmRange : public Observable, public Observer
{
public:
    NvmRange(uint h, uint l, Nvm &nvm);
    NvmRange(const Range &range, Nvm &nvm);
    NvmRange(const NvmRange &other);
    NvmRange &operator=(const NvmRange &other);
    ~NvmRange();
    void forwardUpdates() const;
    void update();
    unsigned int size() const { return _range.size(); }
    QVector<bool> nvmData() const; // move to NVM
    Range range() const { return _range; }

private:
    Range _range;
    mutable bool _updated;
    Nvm *_nvm;

    void registerRange(const Range &range, Nvm *nvm);
    void deRegisterRange(const Range &range, Nvm *nvm);
    void copy(const NvmRange &other);
};

#endif // NVMRANGE_H
