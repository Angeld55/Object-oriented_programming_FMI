#include "SetByCriteria.h"

SetByCriteria::SetByCriteria(unsigned n, bool (*incl)(unsigned n), bool (*excl)(unsigned n)) : SetOfNumbers(n), myCr(incl, excl)
{
    for (unsigned i = 0; i < n; i++)
    {
        if (myCr._incl(i) && !myCr._excl(i))
            addNumber(i);
    }
}

void SetByCriteria::fillSet()
{
    for (unsigned i = 0; i < SetOfNumbers::getMaxNumber(); i++)
    {
        if (myCr._incl(i) && !myCr._excl(i))
            addNumber(i);
        else
            removeNumber(i);
    }
}


bool SetByCriteria::conatins(int i) const
{
    return SetOfNumbers::contains(i);
}
void SetByCriteria::print() const
{
    SetOfNumbers::print();
}


void SetByCriteria::setInclude(bool (*incl)(unsigned n))
{
    myCr._incl = incl;
    removeAll();
    fillSet();
}
void SetByCriteria::setExclude(bool (*excl)(unsigned n))
{
    myCr._excl = excl;
    removeAll();
    fillSet();
}