#pragma once
#include "Validator.h"

class NoDigitValidator: public Validator<std::string> {
public:
	NoDigitValidator();
	bool isValid(const std::string&)const;
	virtual std::string getErrorMessage()const override;
private:
};
