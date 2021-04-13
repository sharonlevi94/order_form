#pragma once
#include <string>
#include "Validator.h"
using std::string;

template< class T >
class Field {
public:
	Field(string);
	addValidator(Validator*);
	int getContent()const;
private:
	string m_message;
	string m_answer;
	//Validator* m_Validator;
};