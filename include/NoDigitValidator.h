#pragma once
#include "Validator.h"

class NoDigitValidator: public Validator<std::string> {
public:
	NoDigitValidator();
	bool isValid(const std::string&)const;
private:
};
