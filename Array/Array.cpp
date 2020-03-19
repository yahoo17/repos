#include "Array.h"

Array::Array(int a):m_size(a)
{

};
Array::Array(Array& a)
{
	if (&a == this)
		return;
	a.m_size = this->m_size;
	int i = 0;
	for (auto x : this->array)
	{
		a.array[i] = x;
		i++;
	}
}

bool Array::operator==(Array& c1)
{
	if(c1.m_size!=this->m_size)
	return false;
	bool arrayeq = false;
	//
	if (arrayeq)
		return true;
	return false;
	{

	}
}

int& Array::operator[](int a)
{
	if (a >= 0 && a <= this->m_size - 1)
		return this->array[a];
	else
		throw "error";
}

int Array::operator[](int a) const
{
	if (a >= 0 && a <= this->m_size - 1)
		return this->array[a];
	else
		throw "error";
}

int Array::size()
{
	return m_size;
}

ostream& operator<<(ostream& os, const Array& c1)
{
	for (int x : c1.array)
		os << x << " ";
	return os;
}

istream& operator>>( istream& is, const Array& c1)
{
	// TODO: 在此处插入 return 语句
	return is;
}
