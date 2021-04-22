#include "Form.h"
#include <iostream>
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
/*
template <typename T>
void Form::addField(Field<T>* field){
	this->m_Fields.emplace_back(field);
}
*/
/*-----------------------------------------------------------------------------*/
/*
template <class T>
void Form::addValidator(Validator<T>* validator){
	if (dynamic_cast<RoomValidator*>(validator))
		this->m_RoomValidator = dynamic_cast<RoomValidator*>(validator);
	this->m_SumValidator = dynamic_cast<SumValidator*>(validator);
}
*/
/*-----------------------------------------------------------------------------*/
////template <class T>
//void Form::fillForm(){
//
//    for (auto field : m_Fields){
//        if (dynamic_cast<Field<>*>(field))
//    }
//}
/*-----------------------------------------------------------------------------*/
bool Form::validateForm() { return true; }