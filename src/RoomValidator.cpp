#include "RoomValidator.h"

RoomValidator::RoomValidator(std::string errorMessage,
                             Field<int>* pairRooms,
                             Field<int>* familyRooms,
                             Field<int>* totalPeople)
        : m_errorMessage(errorMessage){
         this->m_Fields.push_back(pairRooms);
         this->m_Fields.push_back(familyRooms);
         this->m_Fields.push_back(totalPeople);
}
//          m_pairRooms(pairRooms->getContent()),
//          m_familyRooms(familyRooms->getContent()),
//          m_totalPeople(totalPeople->getContent()){}

bool RoomValidator::isValid(const int& obj)const {
    int count_people_by_rooms = (this->m_Fields[0]->getContent() * 2) + (this->m_Fields[1]->getContent() * 5);
            //this->m_pairRooms*2 + this->m_familyRooms*5;
    return this->m_Fields[2]->getContent()<= count_people_by_rooms;

}

std::string RoomValidator::getErrorMessage()const { return this->m_errorMessage; }
