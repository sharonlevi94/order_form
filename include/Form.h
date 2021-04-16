#pragma once
#include "Field.h"
#include <vector>
using std::vector;
/*-----------------------------------------------------------------------------*/
class Form {
public:
	Form();
	template <class T>
	void addField(Field<T>*);
	void addValidator(Validator*);
	void fillForm();
	bool validateForm();
	template <class T>
	vector<Field<T>*> getFields()const;
private:
};
/*-----------------------------------------------------------------------------*/
//template<class T>
std::ostream& operator<<(std::ostream& os, const Form& f);