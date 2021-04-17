#include "DateValidator.h"
#include <ctime>

template <class T>
DateValidator<T>::DateValidator(){}

template <class T>
std::string DateValidator<T>::isValid(const T& obj)const {
	//obj = ddmmyyyy
	int givenDate = (int)obj;
	int givenYear = givenDate % 10000; //year = yyyy
	givenDate /= 10000; //currentDate = ddmm
	int givenMonth = givenDate % 100; // month = mm
	int givenDay = givenDate /= 100; // day =  dd

	time_t now = time(0);
	tm* ltm = localtime(&now);
	int currentYear = 1900 + ltm->tm_year;
	int currentMonth = 1 + ltm->tm_mon;
	int currentDay = ltm->tm_mday;
}