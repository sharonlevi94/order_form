#include "Form.h"
#include <iostream>
/*-----------------------------------------------------------------------------*/

Form::Form()
: m_RoomValidator(nullptr),m_SumValidator(nullptr),m_isCorrect(true){}

/*-----------------------------------------------------------------------------*/

vector<FieldBase*> Form::getFields()const { return this->m_Fields; }

/*-----------------------------------------------------------------------------*/

vector<FormValidator*> Form::getFormValidators()const { return this->m_formValidators; }

/*-----------------------------------------------------------------------------*/

std::ostream& operator<<(std::ostream& os, const Form& f) {
	for (int i = 0; i < f.getFields().size(); i++)
			f.getFields()[i]->printField();

	for (auto form_validator : f.getFormValidators())
		if (!form_validator->getIsCorrect())
			os << form_validator->getErrorMessage();
	return os;
}
/*-----------------------------------------------------------------------------*/
