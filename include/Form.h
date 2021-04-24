#pragma once
#include "FieldBase.h"
#include "Field.h"
#include <vector>
#include "FormValidator.h"
#include "FieldBase.h"
using std::vector;

/*-----------------------------------------------------------------------------*/
class Form {
public:
	Form();
	/*--------------------------------*/

	void addField(FieldBase*);

	/*--------------------------------*/

    void addValidator(FormValidator*);

    /*--------------------------------*/

    void fillForm();

    /*--------------------------------*/
	
    bool validateForm();

	/*--------------------------------*/

	vector<FieldBase*> getFields()const;

    /*--------------------------------*/

    vector<FormValidator*> getFormValidators()const;

	/*--------------------------------*/
private:
    vector<FormValidator*> m_formValidators;
	vector<FieldBase*> m_Fields;
    bool m_isCorrect;
};
/*-----------------------------------------------------------------------------*/

std::ostream& operator<<(std::ostream& os, const Form& f);