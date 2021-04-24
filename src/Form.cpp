#include "Form.h"
#include <iostream>
/*-----------------------------------------------------------------------------*/

Form::Form()
: m_isCorrect(true){}

/*-----------------------------------------------------------------------------*/

vector<FieldBase*> Form::getFields()const 
    { return this->m_Fields; }

/*-----------------------------------------------------------------------------*/

vector<FormValidator*> Form::getFormValidators()const 
    { return this->m_formValidators; }

/*-----------------------------------------------------------------------------*/

std::ostream& operator<<(std::ostream& os, const Form& f) {
	for (int i = 0; i < f.getFields().size(); i++)
			f.getFields()[i]->printField();

	for (auto form_validator : f.getFormValidators())
		if (!form_validator->getIsCorrect())
			os << form_validator->getErrorMessage() << std::endl;
	return os;
}
/*-----------------------------------------------------------------------------*/

void Form::addValidator(FormValidator* validator)
    {this->m_formValidators.push_back(validator);}

/*-----------------------------------------------------------------------------*/

void Form::fillForm() {
    for (auto field : m_Fields) {
        if (!field->getIsCorrect()) {
            if (dynamic_cast<Field<int>*>(field)) {
                std::cout << dynamic_cast<Field<int>*>(field)->getQuestion(); //prints question
                dynamic_cast<Field<int>*>(field)->setAnswer();
            }
            if (dynamic_cast<Field<uint32_t>*>(field)) {
                std::cout << dynamic_cast<Field<uint32_t>*>(field)->getQuestion(); //prints question
                dynamic_cast<Field<uint32_t>*>(field)->setAnswer();
            }
            if (dynamic_cast<Field<std::string>*>(field)) {
                std::cout << dynamic_cast<Field<std::string>*>(field)->getQuestion(); //prints question
                dynamic_cast<Field<std::string>*>(field)->setAnswer();
            }
        }
    }

    for (auto form_validator : m_formValidators) {
        if (!form_validator->getIsCorrect()) {
            for (auto field : form_validator->getFields()) {
                std::cout << dynamic_cast<Field<int>*>(field)->getQuestion(); //prints question
                dynamic_cast<Field<int>*>(field)->setAnswer(); //get new answer from user
            }
        }
    }
}

/*-----------------------------------------------------------------------------*/

bool Form::validateForm() {
    this->m_isCorrect = true;
    for (auto field : m_Fields) {
        // if matches dynamic cast and field data is not valid:
        if (dynamic_cast<Field<int>*>(field) and !dynamic_cast<Field<int>*>(field)->getIsCorrect()) {
            dynamic_cast<Field<int>*>(field)->DoValidation(dynamic_cast<Field<int>*>(field)->getContent());
        }
        // if matches dynamic cast and field data is not valid:
        if (dynamic_cast<Field<uint32_t>*>(field) and !dynamic_cast<Field<uint32_t>*>(field)->getIsCorrect()) {
            dynamic_cast<Field<uint32_t>*>(field)->DoValidation(dynamic_cast<Field<uint32_t>*>(field)->getContent());
        }
        // if matches dynamic cast and field data is not valid:
        if (dynamic_cast<Field<std::string>*>(field) and !dynamic_cast<Field<std::string>*>(field)->getIsCorrect()) {
            dynamic_cast<Field<std::string>*>(field)->DoValidation(dynamic_cast<Field<std::string>*>(field)->getContent());
        }
        if (!field->getIsCorrect())
            if (this->m_isCorrect)
                this->m_isCorrect = false;
    }

    for (auto form_validator : m_formValidators)
        if (!form_validator->isValid())
            this->m_isCorrect = false;

    return this->m_isCorrect;
}

/*-----------------------------------------------------------------------------*/

void Form::addField(FieldBase* field)
{
    this->m_Fields.push_back(field);
}

