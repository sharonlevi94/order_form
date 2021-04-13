#pragma once
#include <string>
#include "Validator.h"
using std::string;

template< class T >
class Field {
public:
	Field(string);
	addValidator(Validator*);
private:
	//Validator* m_Validator;
};