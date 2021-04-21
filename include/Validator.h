#pragma once
#include <string>

template <class T>
class Validator {
public:
    Validator()= default;
    virtual bool isValid(const T& obj)const = 0;
    virtual std::string getErrorMessage()const = 0;

private:
};