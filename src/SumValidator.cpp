#include "SumValidator.h"

/*-----------------------------------------------------------------------------*/

SumValidator::SumValidator(std::string errorMessage, Field<int>* totalPeople,
	Field<int>* kidsUnder, Field<int>* adultAbove)
	: FormValidator::FormValidator(errorMessage, totalPeople, kidsUnder, adultAbove) {}

/*-----------------------------------------------------------------------------*/

bool SumValidator::isValid() {
	if (this->getFields()[0]->getContent() ==
		this->getFields()[1]->getContent() + this->getFields()[2]->getContent()) {
		this->setIsCorrect(true);
		return true;
	}

	this->setIsCorrect(false);
	return false;
}
