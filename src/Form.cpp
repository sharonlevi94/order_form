#include "Form.h"
#include <ostream>

template<class T>
vector<Field<T>*> Form::getFields()const { return this->m_Fields; }

std::ostream& operator<<(std::ostream& os, const Form& f) {
	for (int i = 0; i < f.getFields().size(); i++)
		os << f.getFields()[i];
	return os;
}