#ifndef COMPLEX_H
#define COMPLEX_H
class complex
{

public:
	complex(int real, int image);
public:

	complex operator+(const complex& c2);
	complex operator-(const complex& c2);
	complex operator*(const complex& c2);
	bool operator==(const complex& c2);
	bool operator!=(const complex& c2);
	
public:
	int m_real;
	int m_image;

};




#endif // !COMPLEX_H
