#pragma once
#include "Validator.h"
class SumValidator : public Validator<int> {
public:
	SumValidator(std::string, Field<int>*, Field<int>*, Field<int>*);
	virtual std::string isValid(const int& obj)const override;
private:
};