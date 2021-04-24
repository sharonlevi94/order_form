#pragma once
#include "FieldBase.h"
#include "Field.h"
#include <vector>
#include <string>

class FormValidator {
public:
	FormValidator(std::string, Field<int>*, Field<int>*, Field<int>*);
	virtual bool isValid() = 0;
	virtual std::string getErrorMessage()const;
	virtual std::vector<Field<int>*> getFields()const;
	bool getIsCorrect()const;
	void setIsCorrect(bool);
private:
	std::string m_errorMessage;
	std::vector<Field<int>*> m_Fields;
	bool m_isCorrect;
};