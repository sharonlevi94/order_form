#include "Form.h"
#include <ostream>
/*-----------------------------------------------------------------------------*/
Form::Form()
: m_RoomValidator(nullptr),m_SumValidator(nullptr){}
/*-----------------------------------------------------------------------------*/
vector<FieldBase*> Form::getFields()const { return this->m_Fields; }
/*-----------------------------------------------------------------------------*/

std::ostream& operator<<(std::ostream& os, const Form& f) {
	for (int i = 0; i < f.getFields().size(); i++)
		os << f.getFields()[i];
	return os;
}
/*-----------------------------------------------------------------------------*/
template <class T>
void Form::addField(Field<T>*){}
/*-----------------------------------------------------------------------------*/
void Form::addValidator(Validator* validator){}
/*-----------------------------------------------------------------------------*/
void Form::fillForm(){}
/*-----------------------------------------------------------------------------*/
bool Form::validateForm(){}