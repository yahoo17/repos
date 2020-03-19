#include <iostream>

using namespace std;
class Ration
{
	//use location to represent molecule and Denominator
public:
	int up;
	int down;
public:
	Ration(int up, int down);
	Ration operator+(const Ration& c2);
	Ration operator-(const Ration& c2);
	Ration operator*(const Ration& c2);

	friend  ostream& operator<<(ostream& ouput, const Ration& c2);
	void Contract();
	int measure1(int x, int y)
	{
		int z = y;
		while (x % y != 0)
		{			//定理：两个整数的最大公约数等于其中较小的那个数和两数相除余数的最大公约数。
			z = x % y;
			x = y;
			y = z;
		}
		return z;
	}
};

Ration::Ration(int up, int down) :up(up), down(down)
{

}
Ration Ration::operator+(const Ration& c2)
{
	int up = this->up * c2.down + c2.up * this->down;
	int down = this->down * c2.down;
	Ration c(up, down);
	c.Contract();
	return c;

}

Ration Ration::operator-(const Ration& c2)
{
	int up = this->up * c2.down - c2.up * this->down;
	int down = this->down * c2.down;
	Ration c(up, down);
	c.Contract();
	return c;

}

Ration Ration::operator*(const Ration& c2)
{


	Ration c = Ration(this->up * c2.up, this->down * c2.down);
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
int main()
{
	int r1, r2, r3, r4;
	cin >> r1 >> r2 >> r3 >> r4;
	Ration c1(r1, r2);
	Ration c2(r3, r4);
	if (r2 == 0 || r4 == 0)
	{
		cout << "ERROR";
		return 0;
	}
	else
	{
		cout << (c1 + c2);
		cout << (c1 - c2);
		cout << (c1 * c2);
	}
	return 0;

}
