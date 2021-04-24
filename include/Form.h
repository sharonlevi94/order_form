#pragma once
#include "FieldBase.h"
#include "Field.h"
#include <vector>
#include "FormValidator.h"
#include "RoomValidator.h"
#include "SumValidator.h"
using std::vector;
/*-----------------------------------------------------------------------------*/
class Form {
public:
	Form();
	/*--------------------------------*/

	template <class T>
	void addField(Field<T>* field) 
        {this->m_Fields.push_back(field);};

	/*--------------------------------*/

	void addValidator(FormValidator* validator) 
        {this->m_formValidators.push_back(validator);};

    /*--------------------------------*/

    void fillForm(){
        for (auto field : m_Fields){
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
    }

    /*--------------------------------*/
	
    bool validateForm() {
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
            if (!form_validator->isValid()) {
                std::cout << form_validator->getErrorMessage();
                this->m_isCorrect = false;
            }
        return this->m_isCorrect;
	};
	/*--------------------------------*/
	vector<FieldBase*> getFields()const;
	/*--------------------------------*/
private:
    vector<FormValidator*> m_formValidators;
	RoomValidator* m_RoomValidator;
	SumValidator* m_SumValidator;
	vector<FieldBase*> m_Fields;
    bool m_isCorrect;
};
/*-----------------------------------------------------------------------------*/
std::ostream& operator<<(std::ostream& os, const Form& f);