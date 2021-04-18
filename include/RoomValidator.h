#pragma once
#include "Validator.h"
#include <string>

class RoomValidator : public Validator<int> {
public:
	RoomValidator(std::string, Field<int>*, Field<int>*, Field<int>*);
	virtual std::string isValid(const int& obj)const override;
private:
};