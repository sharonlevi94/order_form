#pragma once
#include "FormValidator.h"
#include <string>
#include <vector>

/*-----------------------------------------------------------------------------*/

class RoomValidator : public FormValidator {
public:
    RoomValidator(std::string, Field<int>*, Field<int>*, Field<int>*);
    virtual bool isValid()override;
};