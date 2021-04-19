#pragma once
#include "Validator.h"

template < class T >
class NonNegativeValidator : public Validator<T> {
public:
	NonNegativeValidator() {};
	virtual std::string isValid(const T&)const override {
		return "";
	};
private:
};