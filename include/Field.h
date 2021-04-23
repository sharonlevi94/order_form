#pragma once
#include "FieldBase.h"
#include "Validator.h"
#include <iostream>
using std::string;
/*--------------------------------*/
template< class T >
class Field : public FieldBase {
public:
	Field(string question) 
		:m_question(question.append(" = ")),
		m_Validator(nullptr){
		m_answer = T(),
		m_isCorrect = false;
//		this->m_isCorrect = true;
	};
	/*--------------------------------*/

	void addValidator(Validator<T>* validator) 
	{ m_Validator = validator; };

	/*--------------------------------*/

	T getContent()const {
		return this->m_answer;
	};

	/*--------------------------------*/
   
	void setAnswer(){std:: cin >> m_answer;}

    /*--------------------------------*/

	string getQuestion()const { return this->m_question; };

	/*--------------------------------*/

	bool getIsCorrect()const { return this->m_isCorrect; };

	/*--------------------------------*/

	 void DoValidation(const T& obj) {
		if (this->m_Validator->isValid(obj))
			this->m_isCorrect = true;
	};

	/*--------------------------------*/

private:
	string m_question;
	T m_answer;
	Validator<T>* m_Validator;
	bool m_isCorrect;
};
	/*--------------------------------*/
template< typename T >
std::ostream& operator<<(std::ostream& os, const Field<T>& f) {
	os << "\n-------------------------------------------------------------------\n"
		<< f.getQuestion() << " = " << f.getContent() << "			";
	if(!f.getIsCorrect())
		os<< f.m_Validator->getErrorMessage();
	os << "\n-------------------------------------------------------------------\n";
	return os;
}

