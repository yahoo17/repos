#ifndef SHAPE_H
#define SHAPE_H
#include <iostream>
#include <QMainWindow>
#include <QPainter>
#include <QRect>
#include <QBrush>
#include <QPen>
#include <QFont>
#include <vector>
#include <iostream>
using std::cout;
using std::vector;
using std::istream;
#define PI 3.1415926
struct point//保存点和向量
{
    int x, y;
    point(int X=0,int Y=0):x(X),y(Y){}
    point& operator=(point p) {
        x = p.x; y = p.y;
        return *this;
    }
    double length() {//求长度
        return sqrt(x * x + y * y);
    }
    int len2() {//求长度平方
        return x * x + y * y;
    }
};
int operator*(point a, point b)//叉积
{
    return a.x * b.y - a.y * b.x;
}
int operator^(point a, point b)//点积
{
    return a.x * b.x + a.y * b.y;
}
point operator+(point a, point b)
{
    return point(a.x + b.x, a.y + b.y);
}
point operator-(point a, point b)
{
    return point(a.x - b.x, a.y - b.y);
}
class Shape
{
public:
    virtual double getPerimeter(){return 0;} ;
    virtual double getArea(){return  0;} ;
};
//圆
class Circle:public Shape
{
public:
    explicit Circle(double x,double y,double radius):radius(radius)
    {
        center[0] = x;
        center[1] = y;

    }
    virtual double getArea()
    {
        m_area = PI * radius * radius;
        return m_area;
    }
    virtual double getPerimeter()
    {
        m_perimeter = 2 * PI * radius;
        return m_perimeter;
    }
    virtual void print()
    {

    }
    virtual bool symmetrical()
    {
        return true;
    }

private:
    double center[2];
    double radius;
    double m_perimeter;
    double m_area;

};
//三角形
class Triangle:public Shape
{

};
//四边形
class Quadrangle:public Shape
{
protected:
    point p1, p2, p3, p4;
    double l1, l2, l3, l4;
    point c1, c2, c3, c4;//保存4条边向量
    int area;//面积
    double peri;//周长
public:
    friend istream& operator>>(istream& c, Quadrangle& x);
    double getArea();
    double getPerimeter();
    void setPoint(int val[8]);
    //更新属性,求面积和周长
    void updateProperty();
    //默认构造函数
    Quadrangle(int x1 = 0, int y1 = 0, int x2 = 0, int y2 = 0, int x3 = 0, int y3 = 0, int x4 = 0, int y4 = 0);
    //赋值构造函数
    Quadrangle(Quadrangle& px);
    Quadrangle& operator=(Quadrangle px);

public:
    vector<int> loc;

};
inline double Quadrangle::getArea() { return area; }

inline double Quadrangle::getPerimeter() { return peri; }

inline void Quadrangle::setPoint(int val[8]) {
    p1 = point(val[0], val[1]);
    p2 = point(val[2], val[3]);
    p3 = point(val[4], val[5]);
    p4 = point(val[6], val[7]);
    updateProperty();
}

//更新属性,求面积和周长
inline void Quadrangle::updateProperty() {
    //以p1为中心点依次求叉积解出四边形面积
    c1 = p2 - p1;
    c2 = p3 - p1;
    c3 = p4 - p1;
    area = abs(c1 * c2 + c2 * c3);
    //然后依次保存4边向量并求出周长
    c2 = p3 - p2;
    c3 = p4 - p3;
    c4 = p1 - p4;
    l1 = c1.length();
    l2 = c2.length();
    l3 = c3.length();
    l4 = c4.length();
    peri = l1 + l2 + l3 + l4;

}

//默认构造函数
inline Quadrangle::Quadrangle(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
    int val[] = { x1,y1,x2,y2,x3,y3,x4,y4 };
    setPoint(val);
}

//赋值构造函数
inline Quadrangle::Quadrangle(Quadrangle& px) {
    p1 = px.p1; p2 = px.p2; p3 = px.p3; p4 = px.p4;
    updateProperty();
}
//赋值运算符
Quadrangle& Quadrangle::operator=(Quadrangle px)
{
    p1 = px.p1; p2 = px.p2; p3 = px.p3; p4 = px.p4;
    updateProperty();
    return *this;
}
//多边形
class Polygon:public Shape
{
public:


};
//菱形
class Rhombus:public Quadrangle
{
public:
};
//平行四边形
class Parallelogram :public Quadrangle
{
public:
    Parallelogram(Quadrangle px);
    //平行四边形判断:两组对边平行
     virtual bool check();
     //构造函数


};
inline Parallelogram::Parallelogram(Quadrangle px) :Quadrangle(px) {
}
inline bool Parallelogram::check() {
    return (c1 * c3 == 0) && (c2 * c4 == 0);
    return false;
}
//正方形
class Square:public  Quadrangle
{
public:
    Square(int x,int y,int sideLength):Quadrangle(x,y,x+sideLength,y,x+sideLength,y+sideLength,x,y+sideLength)
    {

    }

        //构造函数
    Square(Quadrangle px);

};

//矩形
class Rectangele:public  Quadrangle
{
public:
    Rectangele(Quadrangle px);
    Rectangele(int x,int y,int width,int height):Quadrangle(x,y,x+width,y,x+width,y+height,x,y+height)
    {

    }
    virtual bool check();
      //构造函数

};
inline Rectangele::Rectangele(Quadrangle px) :Quadrangle(px) {
}
inline bool Rectangele::check() {
    Parallelogram p(*this);
    if (!p.check()) return false;
    return ((c1 ^ c2) == 0);
}



#endif // SHAPE_H
