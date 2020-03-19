#include "Ration.h"

Ration::Ration(int up, int down) :up(up), down(down)
{

}
Ration Ration::operator+(const Ration& c2)
{
	int up = this->up * c2.down + c2.up * this->up;
	int down = this->down * c2.down;
	Ration c(up, down);
	c.Contract();
	return c;

}

Ration Ration::operator-(const Ration& c2)
{
	int up = this->up * c2.down - c2.up * this->up;
	int down = this->down * c2.down;
	Ration c(up, down);
	c.Contract();
	return c;

}

Ration Ration::operator*(const Ration& c2)
{
	
	
	Ration c= Ration(this->up * c2.up, this->down * c2.down);
	c.Contract();
	return c;
}

void Ration::Contract()
{
	int n = measure1(up, down);
	up /= n;
	down /= n;

	
}



ostream& operator<<(ostream& ouput, const Ration& c2)
{
	ouput << c2.up << "/" << c2.down << endl;
	return ouput;
}
