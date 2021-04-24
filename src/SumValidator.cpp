#include "SumValidator.h"

/*-----------------------------------------------------------------------------*/

SumValidator::SumValidator(std::string errorMessage, Field<int>* totalPeople,
	Field<int>* kidsUnder, Field<int>* adultAbove)
	: FormValidator::FormValidator(errorMessage, totalPeople, kidsUnder, adultAbove) {}

/*-----------------------------------------------------------------------------*/

bool SumValidator::isValid()const {
	if (this->getFields()[0]->getContent() ==
		this->getFields()[1]->getContent() + this->getFields()[2]->getContent())
		return true;

	//set false in all relevante fields for fill them again by user:
	for (auto field : this->getFields())
		field->setIsCorrect(false);
	return false;
}
