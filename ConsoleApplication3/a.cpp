#include "a.h"

//ͳһд�ɳ�Ա����

//this is prefix ++i
Date& Date::operator++()
{
	this->data += 1;
	return *this;
}
Date Date::operator++(int)
{
	Date temp = *this;
	this->data++;
	return *this;

}

