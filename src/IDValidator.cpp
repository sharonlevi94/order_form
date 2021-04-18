#include "IDValidator.h"
#include <vector>
IDValidator::IDValidator(){}

std::string IDValidator::isValid(const uint32_t& id_num)const {
    int int_id = int(id_num);
    std::vector<int> id;
    auto it = id.begin();
    while (id_num != 0) {
        id.insert(it, int_id % 10);
        int_id /= 10;
    }

    if (id.size() !=  9 )   // Make sure ID is formatted properly
        return "Wrong control digit";

    int sum = 0, incNum;
    for (int i=0 ; i < id.size(); i++) {
        incNum = id[i] * ((i % 2) + 1);  // Multiply number by 1 or 2
        sum += (incNum > 9) ? incNum - 9 : incNum;  // Sum the digits up and add to total   
    }
    if (sum % 10 == 0)
        return "";
    return "Wrong control digit";
}