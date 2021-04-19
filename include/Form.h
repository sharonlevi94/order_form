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
	/*--------------------------------*/

	template <class T>
	void addField(Field<T>* field) {
			this->m_Fields.push_back(field);
		};

	/*--------------------------------*/

	template <class T>
	void addValidator(Validator<T>* validator) {
		if (dynamic_cast<RoomValidator*>(validator))
			this->m_RoomValidator = dynamic_cast<RoomValidator*>(validator);
		this->m_SumValidator = dynamic_cast<SumValidator*>(validator);
	};

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