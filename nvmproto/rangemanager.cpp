#include "rangemanager.h"
#include <QListIterator>

NvmRangeManager::NvmRangeManager(Nvm &nvm)
    : _nvmLink(nvm)
{
    _nvmLink.addObserver(this);
}

NvmRange &NvmRangeManager::addNvmRange(const Range &range)
{
    NvmRange nvmRange(range, _nvmLink);
    _nvmRanges.append(nvmRange); //copy! store by pointer or construct in-place
    return _nvmRanges.last(); //TODO: dangerous return
}

void NvmRangeManager::removeNvmRange(unsigned int h, unsigned int l)
{
    Q_UNUSED(h);
    Q_UNUSED(l);
    //add way for easy range search
    Q_ASSERT(false);
}

void NvmRangeManager::update()
{
    QListIterator<NvmRange> i(_nvmRanges); //TODO: update right ranges only
    while (i.hasNext())
        i.next().forwardUpdates();
}
