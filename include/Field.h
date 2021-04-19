#pragma once
#include "FieldBase.h"
#include "Validator.h"
#include <ostream>
using std::string;
/*--------------------------------*/
template< class T >
class Field : public FieldBase {
public:
	Field(string question) 
		:m_question(question),
		m_Validator(nullptr){
		m_answer = T();
		m_errorMessage = string();
		this->m_isCorrect = true;
	};
	/*--------------------------------*/

	void addValidator(Validator<T>* validator) 
	{ m_Validator = validator; };

	/*--------------------------------*/

	T getContent()const {
		return this->m_answer;
	};

	/*--------------------------------*/

	string getErrorMessage() {
		m_errorMessage = m_Validator->isValid();
		if (m_errorMessage != "")
			m_isCorrect = false;
	};

	/*--------------------------------*/

	string getQuestion()const { return this->m_question; };

	/*--------------------------------*/
private:
	string m_question;
	T m_answer;
	string m_errorMessage;
	Validator<T>* m_Validator;
	bool m_isCorrect;
};
	/*--------------------------------*/
template< typename T >
std::ostream& operator<<(std::ostream& os, const Field<T>& f) {
	os << "\n-------------------------------------------------------------------\n"
		<< f.getQuestion() << " = " << f.getContent() << "			" << f.m_errorMessage
		<< "\n-------------------------------------------------------------------\n";
	return os;
}

