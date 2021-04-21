#pragma once
#include "Validator.h"


class IDValidator : public Validator<uint32_t> {
public:
	IDValidator();
	virtual bool isValid(const uint32_t&)const override;
	virtual std::string getErrorMessage()const override;
private:
};