#include "RoomValidator.h"

RoomValidator::RoomValidator(std::string errorMessage,
	Field<int>* f_a,
	Field<int>* f_b,
	Field<int>* f_c)
	: m_errorMessage(errorMessage) {
	this->m_Fields.push_back(f_a);
	this->m_Fields.push_back(f_b);
	this->m_Fields.push_back(f_c);
}

std::string RoomValidator::isValid(const int& obj)const { return ""; }