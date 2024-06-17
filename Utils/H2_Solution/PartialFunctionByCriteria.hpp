#pragma once
#include "PartialFunction.h"

template <typename T>
class PartialFunctionByCriteria : public PartialFunction
{
private:
	T data;
public:
	PartialFunctionByCriteria(const T& data);

	bool isDefined(int32_t val) const override;
	int32_t operator()(int32_t val) const override;
	PartialFunction* clone() const override;
};

template<typename T>
inline PartialFunctionByCriteria<T>::PartialFunctionByCriteria(const T& data) : data(data)
{
}

template<typename T>
inline bool PartialFunctionByCriteria<T>::isDefined(int32_t val) const
{
	return data(val).first;
}

template<typename T>
inline int32_t PartialFunctionByCriteria<T>::operator()(int32_t val) const 
{
	return data(val).second;
}

template<typename T>
inline PartialFunction* PartialFunctionByCriteria<T>::clone() const
{
	return new PartialFunctionByCriteria(*this);
}
