#include "IDValidator.h"

IDValidator::IDValidator(){}

std::string IDValidator::isValid(const std::string& id)const {
    if (id.size() !=  9 )   // Make sure ID is formatted properly
        return "Wrong control digit";

    int sum = 0, incNum;
    for (int i=0 ; i < id.size(); i++) {
        incNum = int(id[i]) * ((i % 2) + 1);  // Multiply number by 1 or 2
        sum += (incNum > 9) ? incNum - 9 : incNum;  // Sum the digits up and add to total   
    }
    if (sum % 10 == 0)
        return "";
    return "Wrong control digit";
}