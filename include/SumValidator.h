#pragma once
#include "FormValidator.h"
#include <string>
#include <vector>

class SumValidator : public FormValidator {
public:
	SumValidator(std::string, Field<int>*, Field<int>*, Field<int>*);
	virtual bool isValid()const override;
};