#include "complex.h"


complex::complex(int real, int image)
{
	m_real = real;
	m_image = image;
}
complex complex::operator+(const complex& c2)
{
	complex c(this->m_real + c2.m_real, this->m_image + c2.m_image);
	return c;
	
	// TODO: �ڴ˴����� return ���
}

complex complex::operator-(const complex& c2)
{

	return complex(this->m_real-c2.m_real,this->m_image-c2.m_image);
}
complex complex::operator*(const complex& c2)
{
	return complex(this->m_real * c2.m_real, this->m_image * c2.m_image);
}

bool complex::operator==(const complex& c2)
{
	if (this->m_real == c2.m_image && this->m_image == c2.m_image)
		return true;
	else
		return false;
}

bool complex::operator!=(const complex& c2)
{
	if (this->m_image != c2.m_image || this->m_real != c2.m_real)
		return false;
	else
		return true;
}
