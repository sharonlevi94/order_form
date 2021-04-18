#include "NoDigitValidator.h"
#include <ctype.h>

NoDigitValidator::NoDigitValidator() {

}

std::string NoDigitValidator::isValid(const std::string & idToCheck) const {
    for (int i = 0; i < idToCheck.length(); ++i) {
        if (!isdigit(idToCheck[i])) {
            return "Can't contain digits";
        }
    }
    return "";
}