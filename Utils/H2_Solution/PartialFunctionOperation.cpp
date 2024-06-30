#include "PartialFunctionOperation.h"
#include <utility>
#include <stdexcept>


PartialFunctionOperation::PartialFunctionOperation(PartialFunction**&& functions, uint16_t size) : size(size)
{
    if (!functions || size == 0)
    {
        throw std::invalid_argument("Error.");
    }

    this->functions = new PartialFunction*[size] {nullptr};
    for (uint16_t i = 0; i < size; i++)
    {
        if (!functions[i])
        {
            free();
            throw std::invalid_argument("No existing function.");
        }

        
        this->functions[i] = functions[i];
        functions[i] = nullptr;
    }
}

PartialFunctionOperation::PartialFunctionOperation(const PartialFunctionOperation& other) : PartialFunction(other)
{
    copyFrom(other);
}

PartialFunctionOperation::PartialFunctionOperation(PartialFunctionOperation&& other) : PartialFunction(std::move(other)) noexcept
{
    moveFrom(std::move(other));
}

PartialFunctionOperation& PartialFunctionOperation::operator=(const PartialFunctionOperation& other)
{
    if (this != &other)
    {
        PartialFunction::operator=(std::move(other));
        free();
        copyFrom(other);
    }

    return *this;
}

PartialFunctionOperation& PartialFunctionOperation::operator=(PartialFunctionOperation&& other) noexcept
{
    if (this != &other)
    {
        PartialFunction::operator=(std::move(other));
        free();
        moveFrom(std::move(other));
    }

    return *this;
}

PartialFunctionOperation::~PartialFunctionOperation() noexcept
{
    free();
}

bool PartialFunctionOperation::isDefined(int32_t value) const
{
    for (uint16_t i = 0; i < size; i++)
    {
        if (!functions[i]->isDefined(value))
        {
            return false;
        }
    }

    return true;
}

void PartialFunctionOperation::free()
{
    for (uint16_t i = 0; i < size; i++)
    {
        delete functions[i];
        functions[i] = nullptr;
    }

    delete[] functions;
    functions = nullptr;
    size = 0;
}

void PartialFunctionOperation::copyFrom(const PartialFunctionOperation& other)
{
    for (uint16_t i = 0; i < other.size; i++)
    {
        
       functions[i] = other.functions[i]->clone();
    }

    size = other.size;
}

void PartialFunctionOperation::moveFrom(PartialFunctionOperation&& other)
{
    functions = other.functions;
    other.functions = nullptr;

    size = other.size;
    other.size = 0;
}
