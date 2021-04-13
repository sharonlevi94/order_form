#pragma once
#include "Field.h"
#include <vector>
using std::vector;

class Form {
public:
	Form();
	void addField(Field*);
	void addValidator(Validator*);
	void fillForm();
	bool validateForm();
private:
	vector<Field*> m_Fields;
};