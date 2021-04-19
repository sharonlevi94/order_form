#pragma once
#include "Validator.h"

template < class T >
class NotGreaterThanValidator : public Validator<T> {
public:
	NotGreaterThanValidator(int) {};
	virtual std::string isValid(const T& obj)const override { return ""; };
private:
};