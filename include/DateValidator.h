#pragma once
#include "Validator.h"
#include "RangeValidator.h"
#include "macros.h"
#include <memory>
#include <string>
#include <vector>
#include <ctime>

template < class T >
class DateValidator : public Validator< T > {
public:
	DateValidator() = default;

    bool isValid(const T& obj)const override {
		//obj = ddmmyyyy
		int givenDate = (int)obj;
		int givenYear = givenDate % 10000; //year = yyyy
		givenDate /= 10000; //currentDate = ddmm
		int givenMonth = givenDate % 100; // month = mm
		int givenDay = givenDate / 100; // day =  dd

		time_t now = time(nullptr);
		tm* ltm = localtime(&now);
		int currentYear = 1900 + ltm->tm_year;
		int currentMonth = 1 + ltm->tm_mon;
		int currentDay = ltm->tm_mday;

		if (givenYear >= currentYear) {
            // validator to check if month in range- to save code lines- code reuse!
            std::unique_ptr<RangeValidator<int>> monthValidator = std::make_unique<RangeValidator<int>>(Jan, Dec);
            if (monthValidator->isValid(givenMonth)){
                if (givenYear == currentYear and givenMonth < currentMonth) return false; // if earlier this year
                std::unique_ptr<RangeValidator<int>> dayValidator;
                // if February
                if (givenMonth == Feb){
                    // if the year is a leap year-> feb has 29 days
                    if ((givenYear / 4 && !givenYear / 100) or givenYear / 400){
                        dayValidator = std::make_unique<RangeValidator<int>>(FirstDay, (FebEnd+1));
                    }else
                        dayValidator = std::make_unique<RangeValidator<int>>(FirstDay, FebEnd);
                 // has 30 days:
                }else if ((givenMonth == Apr) or (givenMonth == Jun) or (givenMonth == Sep) or (givenMonth == Nov)){
                    dayValidator = std::make_unique<RangeValidator<int>>(FirstDay, LongMonthEnd);
                } else  // if has 31 days:
                    dayValidator = std::make_unique<RangeValidator<int>>(FirstDay, LongMonthEnd);
                if (dayValidator->isValid(givenDay)) {
                    if ((givenMonth == currentMonth) and givenDay < currentDay) return false; // if earlier this month
                    return true;
                }
            }
		}
		return false;
	}
    std::string getErrorMessage()const override { return "Out of range"; };

};

