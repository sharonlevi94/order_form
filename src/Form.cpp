#include "Form.h"
#include <iostream>
/*-----------------------------------------------------------------------------*/
Form::Form()
: m_RoomValidator(nullptr),m_SumValidator(nullptr),m_isCorrect(true){}
/*-----------------------------------------------------------------------------*/
vector<FieldBase*> Form::getFields()const { return this->m_Fields; }
/*-----------------------------------------------------------------------------*/

std::ostream& operator<<(std::ostream& os, const Form& f) {
	for (int i = 0; i < f.getFields().size(); i++)
			f.getFields()[i]->printField();
	return os;
}
/*-----------------------------------------------------------------------------*/
