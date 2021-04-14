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
	string m_answer;
	string m_errorMessage;
	Validator* m_Validator;
};

template< class T >
std::ostream& operator<<(std::ostream& os, const Field<T>& f);

