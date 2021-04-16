#include "Field.h"
#include <ostream>
/*-----------------------------------------------------------------------------*/
template<typename T>
Field<T>::Field(string question)
	: m_question(question), 
	  m_Validator(nullptr) {
	m_answer = T();
	m_errorMessage = string();
}
/*-----------------------------------------------------------------------------*/
template<typename T>
T Field<T>::getContent()const { return this->m_answer; }
/*-----------------------------------------------------------------------------*/
template<typename T>
string Field<T>::getErrorMessage() {
	m_errorMessage = m_Validator->isValid();
}
/*-----------------------------------------------------------------------------*/
template<typename T>
string Field<T>::getQuestion()const { return this->m_question; }
/*-----------------------------------------------------------------------------*/
template<typename T>
void Field<T>::addValidator(Validator* validator) {
	m_Validator = validator;
}
/*-----------------------------------------------------------------------------*/
template<typename T>
std::ostream& operator<<(std::ostream& os, const Field<T>& f)
{
	os << "\n-------------------------------------------------------------------\n" 
	<< f.getQuestion() << " = " << f.getContent() << "			" << f.m_errorMessage
	<< "\n-------------------------------------------------------------------\n"
		return os;
}