#pragma once
#include "Validator.h"

template < class T >
class NotGreaterThanValidator : public Validator<T> {
public:
	NotGreaterThanValidator(int) {};
	bool isValid(const T& obj)const override { return true; };
private:
};