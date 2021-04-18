#pragma once
#include <string>

template <class T>
class Validator {
public:
	virtual std::string isValid(const T& obj)const = 0;
};