#include "SetByCriteria.h"

SetByCriteria::SetByCriteria(unsigned n, bool (*incl)(unsigned n)) : DynamicSet(n)
{
    fillSet(incl);
}

void SetByCriteria::fillSet(bool (*criteria)(unsigned n))
{
    for (unsigned i = 0; i < getN(); i++)
    {
        if (criteria(i))
            add(i);
        else
            remove(i);
    }
}


void SetByCriteria::setInclude(bool (*incl)(unsigned n))
{
    fillSet(incl);
}
