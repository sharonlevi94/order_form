#include "IDValidator.h"
#include <vector>
IDValidator::IDValidator()= default;

bool IDValidator::isValid(const uint32_t& id_num)const {
    int int_id = int(id_num);
    std::vector<int> id = {};
    //auto it = id.begin();
    while (int_id != 0) {
        id.push_back(int_id % 10);
        int_id /= 10;
    }

    if (id.size() !=  9 )   // Make sure ID is formatted properly
        return false;

    int sum = 0, incNum;
    for (int i = id.size()-1 ; i >= 0 ; i--) {
        incNum = id[i] * ((i % 2) + 1);  // Multiply number by 1 or 2
        sum += (incNum > 9) ? incNum - 9 : incNum;  // Sum the digits up and add to total   
    }
    if (sum % 10 == 0)
        return true;
    return false;
}

std::string IDValidator::getErrorMessage()const { return "Wrong control digit"; }