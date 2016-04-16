#ifndef RANGE_H
#define RANGE_H

typedef unsigned int uint;

class Range
{
public:
    Range();
    Range(uint index) : _h(index), _l(index), _valid(testValid()) {}
    Range(uint hIndex, uint lIndex);
    bool isValid() const { return _valid; }
    uint hIndex() const { return _h; }
    uint lIndex() const { return _l; }
    void setBounds(uint h, uint l);
    uint size() const { return _h - _l + 1; }


private:
    uint _h;
    uint _l;
    bool _valid;

    inline bool testValid() { return (_h >= _l); }
};


#endif // RANGE_H
