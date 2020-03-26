#include <vector>
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
//四边形
class Point
{
public:
	Point(int a, int b);
	double  x, y;
	
};
class Quadrilateral
{
public:
	Quadrilateral();
	vector <Point> polygon;
	
	int getArea2();
	double getDis(double x1, double y1, double x2, double y2);
	double getPerimeter();
	//声明成纯虚函数
	friend istream& operator>>(istream& is, Quadrilateral& a);
	virtual bool check();
};
//梯形

class Trapezoid:public Quadrilateral
{
public:
	Trapezoid();
	Trapezoid(Quadrilateral a);
	bool check();
	 

};
//平行四边形
class Parallelogram :public Quadrilateral
{
public:
	Parallelogram();
	Parallelogram(Quadrilateral a);
	bool check();

};
//矩形
class Rectangle :public Parallelogram
{
public:
	Rectangle();
	Rectangle(Quadrilateral a);
	bool check();
};
//正方形
class Square :public Rectangle

{
public:
	Square();
	Square(Quadrilateral a);
	bool check();
};