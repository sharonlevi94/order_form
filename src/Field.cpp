#include "Field.h"
#include <ostream>
/*-----------------------------------------------------------------------------*/
template<class T>
Field<T>::Field(string question)
	: m_question(question), 
	  m_Validator(nullptr) {
	m_answer = string();
	m_errorMessage = string();
}
/*-----------------------------------------------------------------------------*/
template<class T>
T Field<T>::getContent()const { return this->m_answer; }
/*-----------------------------------------------------------------------------*/
template<class T>
string Field<T>::getErrorMessage() {
	m_errorMessage = m_Validator->isValid();
}
/*-----------------------------------------------------------------------------*/
template<class T>
string Field<T>::getQuestion()const { return this->m_question; }
/*-----------------------------------------------------------------------------*/
template<class T>
void Field<T>::addValidator(Validator* validator) {
	m_Validator = validator;
}
/*-----------------------------------------------------------------------------*/
template<class T>
std::ostream& operator<<(std::ostream& os, const Field<T>& f)
{
	os << "\n-------------------------------------------------------------------\n" 
	<< f.getQuestion() << " = " << f.getContent() << "			" << f.m_errorMessage
	<< "\n-------------------------------------------------------------------\n"
		return os;
}