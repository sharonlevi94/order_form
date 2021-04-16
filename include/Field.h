#pragma once
#include <string>
#include "Validator.h"
using std::string;

template< class T >
class Field {
public:
	Field(string);
	void addValidator(Validator*);
	T getContent()const;
	string getErrorMessage();
	string getQuestion()const;
private:
	string m_question;
	T m_answer;
	string m_errorMessage;
	Validator* m_Validator;
};

template< typename T >
std::ostream& operator<<(std::ostream& os, const Field<T>& f);

