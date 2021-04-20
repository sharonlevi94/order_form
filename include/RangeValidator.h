#pragma once
#include "Validator.h"

template < class T > 
class RangeValidator : public Validator<T> {
public:
	RangeValidator(T min, T max)
		:m_max(max), m_min(min) {};

	bool isValid(const T& obj)const override {
		if (!(obj > this->m_min && obj < this->m_max))
			return false;
		return true;
	};
private:
	T m_max, m_min;
};