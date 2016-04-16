#ifndef RANGEBOSS_H
#define RANGEBOSS_H

#include "observer.h"
#include "nvmrange.h"
#include "nvm.h"

#include <QList>

class NvmRangeManager : public Observer
{
public:
    NvmRangeManager(Nvm &nvm);
    NvmRange &addNvmRange(const Range &range);
    void removeNvmRange(unsigned int h, unsigned int l); //TODO: implement
    void update();
private:
    QList<NvmRange> _nvmRanges;
    Nvm &_nvmLink;
};

#endif // RANGEBOSS_H
