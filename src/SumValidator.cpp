#include "SumValidator.h"

SumValidator::SumValidator(std::string errorMessage,
	Field<int>* f_a,
	Field<int>* f_b,
	Field<int>* f_c)
	: m_errorMessage(errorMessage){
	this->m_Fields.push_back(f_a);
	this->m_Fields.push_back(f_b);
	this->m_Fields.push_back(f_c);
}

bool SumValidator::isValid(const int& obj)const { 
	if (this->m_Fields[0]->getContent() ==
		this->m_Fields[1]->getContent() + this->m_Fields[2]->getContent())
		return true;
	return false;
}