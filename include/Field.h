#pragma once
#include "FieldBase.h"
#include "Validator.h"
#include <iostream>
using std::string;
/*--------------------------------*/
template< class T >
class Field : public FieldBase {
public:
	explicit Field(string question)
		:m_question(question.append(" ")),
		m_Validator(nullptr){
		m_answer = T();
		m_isCorrect = false;
	};
	/*--------------------------------*/

	void addValidator(Validator<T>* validator) 
	{ m_Validator = validator; };

	/*--------------------------------*/

	T getContent()const {
		return this->m_answer;
	};

	/*--------------------------------*/
   
	void setAnswer() override
	{std:: cin >> m_answer;}

    /*--------------------------------*/

	string getQuestion()const 
	{ return this->m_question; };

	/*--------------------------------*/

	virtual bool getIsCorrect()const override
	{ return this->m_isCorrect; };

	/*--------------------------------*/

	virtual void setIsCorrect(bool update) override
	{this->m_isCorrect = update;};

	/*--------------------------------*/

	 void DoValidation(const T& obj) {
		if (this->m_Validator->isValid(obj))
			this->m_isCorrect = true;
	};

	/*--------------------------------*/

	 virtual void printField()const override {
		 std::cout << "-------------------------------------------------------------------------------------------\n"
			 << this->getQuestion() << "= " << this->getContent() << "		";
		 if (!this->getIsCorrect())
			 std::cout << this->m_Validator->getErrorMessage();
		 std::cout << "\n-------------------------------------------------------------------------------------------\n";
	 };

	/*--------------------------------*/

private:
	string m_question;
	T m_answer;
	Validator<T>* m_Validator;
	bool m_isCorrect;
};
	/*--------------------------------*/


