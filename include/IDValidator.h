#pragma once
#include "Validator.h"
class IDValidator : public Validator {
public:
	IDValidator();
	virtual std::string isValid(const std::string&)const;
private:
};