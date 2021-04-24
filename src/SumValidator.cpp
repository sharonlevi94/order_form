#include "SumValidator.h"
#include "macros.h"
/*-----------------------------------------------------------------------------*/

SumValidator::SumValidator(std::string errorMessage, Field<int>* totalPeople,
	Field<int>* kidsUnder, Field<int>* adultAbove)
	: FormValidator::FormValidator(errorMessage, totalPeople, kidsUnder, adultAbove) {}

/*-----------------------------------------------------------------------------*/

bool SumValidator::isValid() {
	if (this->getFields()[people]->getContent() ==
		this->getFields()[kids]->getContent() + this->getFields()[adults]->getContent()) {
		this->setIsCorrect(true);
		return true;
	}

	this->setIsCorrect(false);
	return false;
}
