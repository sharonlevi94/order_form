#pragma once
#include "FieldBase.h"
#include "Field.h"
#include <vector>
#include "RoomValidator.h"
#include "SumValidator.h"
using std::vector;
/*-----------------------------------------------------------------------------*/
class Form {
public:
	Form();
	template <class T>
	void addField(Field<T>*);
	/*--------------------------------*/
	template <class T>
	void addValidator(Validator<T>*);
	void fillForm();
	bool validateForm();
	/*--------------------------------*/
	vector<FieldBase*> getFields()const;
	/*--------------------------------*/
private:
	RoomValidator* m_RoomValidator;
	SumValidator* m_SumValidator;
	vector<FieldBase*> m_Fields;
};
/*-----------------------------------------------------------------------------*/
std::ostream& operator<<(std::ostream& os, const Form& f);