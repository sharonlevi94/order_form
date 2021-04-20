#pragma once
#include "Validator.h"
#include "Field.h"
#include <string>
#include <vector>

class SumValidator : public Validator<int> {
public:
	SumValidator(std::string, Field<int>*, Field<int>*, Field<int>*);
	virtual bool isValid(const int& obj)const override;
private:
	std::string m_errorMessage;
	std::vector<Field<int>*> m_Fields;
};