#include "a.h"

//统一写成成员函数

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

