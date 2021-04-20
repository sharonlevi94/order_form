#pragma once
#include "Validator.h"

template < class T >
class NonNegativeValidator : public Validator<T> {
public:
	NonNegativeValidator() = default;;
	bool isValid(const T&)const override {
		return true;
	};
private:
};