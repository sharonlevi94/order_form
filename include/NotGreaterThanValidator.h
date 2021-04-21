#pragma once
#include "Validator.h"

template < class T >
class NotGreaterThanValidator : public Validator<T> {
public:
	NotGreaterThanValidator(T delta): m_delta(delta) {};
	 
	bool isValid(const T& obj1)const override { 
		return obj1 <= this->m_delta;
	};

private:
	T m_delta;
};