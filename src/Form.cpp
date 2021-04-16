#include "Form.h"
#include <ostream>


/*-----------------------------------------------------------------------------*/
Form::Form()
{}
/*-----------------------------------------------------------------------------*/
template <class T>
vector<Field<T>*> Form::getFields()const { return this->m_Fields; }
/*-----------------------------------------------------------------------------*/
//template <class T>
std::ostream& operator<<(std::ostream& os, const Form& f) {
	for (int i = 0; i < f.getFields().size(); i++)
		os << f.getFields()[i];
	return os;
}