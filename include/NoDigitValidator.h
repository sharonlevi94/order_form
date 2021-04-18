#pragma once
#include "Validator.h"
class NoDigitValidator: public Validator {
public:
    NoDigitValidator();
    virtual std::string isValid(const std::string&)const;
private:
};