#include "RangeValidator.h"

template< class T >
RangeValidator<T>::RangeValidator(T min, T max)
	: m_max(max), m_min(min) {}

template< class T >
std::string RangeValidator<T>::isValid(const T& obj)const{
	if (!(obj > min && obj < max))
		return ("Out of range");
	return "";
}