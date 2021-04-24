#include "RoomValidator.h"
#include "macros.h"
/*-----------------------------------------------------------------------------*/

RoomValidator::RoomValidator(std::string errorMessage, Field<int>* pairRooms,
    Field<int>* familyRooms, Field<int>* totalPeople)
        : FormValidator::FormValidator(errorMessage, pairRooms, familyRooms, totalPeople){}

/*-----------------------------------------------------------------------------*/

bool RoomValidator::isValid(){
    int count_people_by_rooms = (this->getFields()[pair]->getContent() * 2) + (this->getFields()[family]->getContent() * 5);
    if (this->getFields()[total]->getContent() <= count_people_by_rooms) {
        this->setIsCorrect(true);
        return true;
    }

    this->setIsCorrect(false);
    return false;
}

