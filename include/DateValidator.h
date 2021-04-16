#pragma once
#include "Validator.h"
#include <ctime>

template < class T >
class DateValidator : public Validator {
public:
	DateValidator();
	virtual std::string isValid(const T& obj)const override;
private:
	
};