#include <vector>
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
//�ı���
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
	//�����ɴ��麯��
	friend istream& operator>>(istream& is, Quadrilateral& a);
	virtual bool check();
};
//����

class Trapezoid:public Quadrilateral
{
public:
	Trapezoid();
	Trapezoid(Quadrilateral a);
	bool check();
	 

};
//ƽ���ı���
class Parallelogram :public Quadrilateral
{
public:
	Parallelogram();
	Parallelogram(Quadrilateral a);
	bool check();

};
//����
class Rectangle :public Parallelogram
{
public:
	Rectangle();
	Rectangle(Quadrilateral a);
	bool check();
};
//������
class Square :public Rectangle

{
public:
	Square();
	Square(Quadrilateral a);
	bool check();
};