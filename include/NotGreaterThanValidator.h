#pragma once
#include "Validator.h"

template < class T >
class NotGreaterThanValidator : public Validator<T> {
public:
	explicit NotGreaterThanValidator(T delta): m_delta(delta) {};
	 
	bool isValid(const T& obj1)const override { 
		return obj1>=0 && obj1 <= this->m_delta;
	};

	std::string getErrorMessage()const override { return "The maximum is 10 rooms"; };

private:
	T m_delta;
};