#pragma once
#include "Validator.h"

template < class T >
class NonNegativeValidator : public Validator<T> {
public:
    NonNegativeValidator() = default;;

    bool isValid(const T& obj)const override {
        if (obj >= 0)
            return true;
        return false;
    };

    std::string getErrorMessage()const override { return "Can't be negative"; };
    
private:
};