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
		if (dynamic_cast<RoomValidator*>(validator)) {
            this->m_RoomValidator = dynamic_cast<RoomValidator *>(validator);
            return;
		}
		this->m_SumValidator = dynamic_cast<SumValidator*>(validator);
	};
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
        // need to fix room and people validators
        if (!this->m_RoomValidator->isValid(0)){
            std::cout << this->m_RoomValidator->getErrorMessage();
            this->m_isCorrect = false;
        }
        if(!this->m_SumValidator->isValid(0) ){
            std::cout << this->m_RoomValidator->getErrorMessage();
            this->m_isCorrect = false;
        }

        return this->m_isCorrect;
	};
	/*--------------------------------*/
	vector<FieldBase*> getFields()const;
	/*--------------------------------*/
private:
	RoomValidator* m_RoomValidator;
	SumValidator* m_SumValidator;
	vector<FieldBase*> m_Fields;
    bool m_isCorrect;
};
/*-----------------------------------------------------------------------------*/
std::ostream& operator<<(std::ostream& os, const Form& f);