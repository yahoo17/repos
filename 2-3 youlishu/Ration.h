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
		{			//�����������������Լ���������н�С���Ǹ���������������������Լ����
			z = x % y;
			x = y;
			y = z;
		}
		return z;
	}
};

