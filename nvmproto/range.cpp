#include "range.h"
#include "assert.h"

Range::Range()
    : _h(0),
      _l(0),
    _valid(testValid()) //order dependent
{
}

Range::Range(uint hIndex, uint lIndex)
    : _h(hIndex),
      _l(lIndex),
    _valid(testValid()) //order dependent
{
}

void Range::setBounds(uint h, uint l)
{
    assert(h >= l);
    _h = h;
    _l = l;
    _valid = testValid();
}
