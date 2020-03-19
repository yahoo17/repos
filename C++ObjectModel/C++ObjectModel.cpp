#include <iostream>
template <typename type>
class Point3d
{
public :
	type _x;
	type _y;
	type _z;
public:
	Point3d(type fpx, type fpy, type fpz)
	{
		_x = fpx;
		_y = fpy;
		_z = fpz;

	 }




};

using namespace std;
void operator<<(ostream& os, Point3d<int> & obj)
{
	os << obj._x << endl << obj._y << endl << obj._z << endl;

}

int main()
{
	Point3d<int> test(10, 20, 30);
	cout << test;

}