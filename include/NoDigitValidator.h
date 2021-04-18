#pragma once
#include "Validator.h"

class NoDigitValidator: public Validator<std::string> {
public:
	NoDigitValidator() {};
	virtual std::string isValid(const std::string&)const override;
private:
};
