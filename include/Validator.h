#pragma once
#include <string>

class Validator {
public:
	virtual std::string isValid()const = 0;
};