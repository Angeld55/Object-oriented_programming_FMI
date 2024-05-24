#pragma once

template<class FunctionOne, class FunctionTwo>
class IntFunctionAverage
{
private:
    FunctionOne first;
    FunctionTwo second;
public:
    IntFunctionAverage(const FunctionOne& fOne, const FunctionTwo& fTwo) :
        first(fOne),
        second(fTwo) {}

    double average(int x) const
    {
        return (first(x) + second(x)) / 2.0;
    }
};