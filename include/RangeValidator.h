#pragma once
#include "Validator.h"

template < class T > 
class RangeValidator : public Validator<T> {
public:
	RangeValidator(T min, T max);
	virtual std::string isValid(const T& obj)const override;
private:
	T m_max, m_min;
};