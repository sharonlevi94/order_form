#include "NoDigitValidator.h"
#include <ctype.h>

NoDigitValidator::NoDigitValidator() {}

bool NoDigitValidator::isValid(const std::string& idToCheck) const {
    for (int i = 0; i < idToCheck.length(); ++i) {
        if (isdigit(idToCheck[i])) {
            return false;
        }
    }
    return true;
}

std::string NoDigitValidator::getErrorMessage()const { return "Can't contain digits"; }