#pragma once
#include "../SetOfNumbers/SetOfNumbers.h"

class SetByCriteria : private SetOfNumbers
{
public:
    struct Criteria
    {
        Criteria(bool (*incl)(unsigned n), bool (*excl)(unsigned n)) : _incl(incl), _excl(excl) {}
        bool (*_incl)(unsigned n);
        bool (*_excl)(unsigned n);
    };
private:
    Criteria myCr;
    void fillSet();

public:
    SetByCriteria(unsigned n, bool (*incl)(unsigned n), bool (*excl)(unsigned n));
    bool contains(int i) const;
    void print() const;

    void setInclude(bool (*incl)(unsigned n));
    void setExclude(bool (*excl)(unsigned n));

};
