#pragma once
#include "Validator.h"

template < class T >
class DateValidator : public Validator {
public:
	DateValidator();
	virtual std::string isValid(const T& obj)const override;
private:
	
};