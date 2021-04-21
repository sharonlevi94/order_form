#pragma once
#include "Validator.h"
#include "Field.h"
#include <string>
#include <vector>

class RoomValidator : public Validator<int> {
public:
	RoomValidator(std::string, Field<int>*, Field<int>*, Field<int>*);
	virtual bool isValid(const int& obj)const override;
	virtual std::string getErrorMessage()const override;
private:
	std::string m_errorMessage;
	std::vector<Field<int>*> m_Fields;
};