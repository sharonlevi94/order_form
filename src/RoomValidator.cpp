#include "RoomValidator.h"

/*-----------------------------------------------------------------------------*/

RoomValidator::RoomValidator(std::string errorMessage, Field<int>* pairRooms,
    Field<int>* familyRooms, Field<int>* totalPeople)
        : FormValidator::FormValidator(errorMessage, pairRooms, familyRooms, totalPeople){}

/*-----------------------------------------------------------------------------*/

bool RoomValidator::isValid(){
    int count_people_by_rooms = (this->getFields()[0]->getContent() * 2) + (this->getFields()[1]->getContent() * 5);
    if (this->getFields()[2]->getContent() <= count_people_by_rooms) {
        this->setIsCorrect(true);
        return true;
    }

    this->setIsCorrect(false);
    return false;
}

