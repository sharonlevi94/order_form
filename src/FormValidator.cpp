#include "FormValidator.h"

FormValidator::FormValidator(std::string errorMessage,
	Field<int>* field1,
	Field<int>* field2,
	Field<int>* field3)
	: m_errorMessage(errorMessage),
	m_isCorrect(true) {
	this->m_Fields.push_back(field1);
	this->m_Fields.push_back(field2);
	this->m_Fields.push_back(field3);
}

std::string FormValidator::getErrorMessage()const{ return this->m_errorMessage; }

std::vector<Field<int>*> FormValidator::getFields()const { return this->m_Fields; }