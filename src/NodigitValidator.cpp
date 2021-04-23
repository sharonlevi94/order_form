#include "NoDigitValidator.h"
//#include <ctype.h>

NoDigitValidator::NoDigitValidator() = default;

bool NoDigitValidator::isValid(const std::string& nameToCheck) const {
    for (char i : nameToCheck) {
        if (isdigit(i)) {
            return false;
        }
    }
    return true;
}

std::string NoDigitValidator::getErrorMessage()const { return "Can't contain digits"; }