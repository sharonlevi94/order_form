#include "RoomValidator.h"

RoomValidator::RoomValidator(std::string errorMessage,
                             Field<int>* pairRooms,
                             Field<int>* familyRooms,
                             Field<int>* totalPeople)
        : m_errorMessage(errorMessage),
          m_pairRooms(pairRooms->getContent()),
          m_familyRooms(familyRooms->getContent()),
          m_totalPeople(totalPeople->getContent()){}

bool RoomValidator::isValid(const int& obj)const {
    int count_people_by_rooms = this->m_pairRooms*2 + this->m_familyRooms*5;
    return this->m_totalPeople <= count_people_by_rooms;
}

std::string RoomValidator::getErrorMessage()const { return this->m_errorMessage; }
