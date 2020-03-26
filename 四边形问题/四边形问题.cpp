#include<iostream>
#include<string>
#include<cmath>
#include<iomanip>
#include<algorithm>
using namespace std;
class point

{
public:
    int x, y;
    point(int X = 0, int Y = 0) :x(X), y(Y) {}
    point& operator=(point p) {
        x = p.x; y = p.y;
        return *this;
    }
    double length() 
    {
        return sqrt(x * x + y * y);
    }
    int len2() {
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
class Quadrilateral
{
protected:
    point p1, p2, p3, p4;
    double l1, l2, l3, l4;
    point c1, c2, c3, c4;//保存4条边向量
    int area;//面积
    double peri;//周长
public:
    friend istream& operator>>(istream& c, Quadrilateral& x);
    int getArea2();
    double getPerimeter();
    void setPoint(int val[8]);
    //更新属性,求面积和周长
    void updateProperty();
    //默认构造函数
    Quadrilateral(int x1 = 0, int y1 = 0, int x2 = 0, int y2 = 0, int x3 = 0, int y3 = 0, int x4 = 0, int y4 = 0);
    //赋值构造函数
    Quadrilateral(Quadrilateral& px);
    Quadrilateral& operator=(Quadrilateral px);
};
class Trapezoid : public Quadrilateral
{
public:
    //梯形判断,判别方法:一组对边平行,另一组不平行
    virtual bool check();
    //构造函数
    Trapezoid(Quadrilateral px);
};
class Parallelogram :public Quadrilateral
{
public:
    //平行四边形判断:两组对边平行
    virtual bool check();
    //构造函数
    Parallelogram(Quadrilateral px);
};
class Rectangle : public Parallelogram
{
public:
    //矩形判断,先判断平行四边形,然后相邻边垂直
    virtual bool check();
    //构造函数
    Rectangle(Quadrilateral px);
};
class Square : public Rectangle
{
public:
    //正方形判断:先判断矩形,然后判断邻边相等(注意长度平方避免出现浮点数)
    virtual bool check();
    //构造函数
    Square(Quadrilateral px);
};

istream& operator>>(istream& c, Quadrilateral& x)
{
    int val[8];
    for (int i = 0; i < 8; i++) c >> val[i];
    x.setPoint(val);
    return c;
}



inline int Quadrilateral::getArea2() { return area; }

inline double Quadrilateral::getPerimeter() { return peri; }

inline void Quadrilateral::setPoint(int val[8]) {
    p1 = point(val[0], val[1]);
    p2 = point(val[2], val[3]);
    p3 = point(val[4], val[5]);
    p4 = point(val[6], val[7]);
    updateProperty();
}

//更新属性,求面积和周长
inline void Quadrilateral::updateProperty() {
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
inline Quadrilateral::Quadrilateral(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
    int val[] = { x1,y1,x2,y2,x3,y3,x4,y4 };
    setPoint(val);
}

//赋值构造函数
inline Quadrilateral::Quadrilateral(Quadrilateral& px) {
    p1 = px.p1; p2 = px.p2; p3 = px.p3; p4 = px.p4;
    updateProperty();
}
//赋值运算符
Quadrilateral& Quadrilateral::operator=(Quadrilateral px)
{
    p1 = px.p1; p2 = px.p2; p3 = px.p3; p4 = px.p4;
    updateProperty();
    return *this;
}

//梯形判断,判别方法:一组对边平行,另一组不平行
inline bool Trapezoid::check() {
    if (c1 * c3 == 0) return (c2 * c4 != 0);
    if (c2 * c4 == 0) return (c1 * c3 != 0);
    return false;
}

//构造函数
inline Trapezoid::Trapezoid(Quadrilateral px) :Quadrilateral(px) {
}

//平行四边形判断:两组对边平行
inline bool Parallelogram::check() {
    return (c1 * c3 == 0) && (c2 * c4 == 0);
    return false;
}

//构造函数
inline Parallelogram::Parallelogram(Quadrilateral px) :Quadrilateral(px) {
}

//矩形判断,先判断平行四边形,然后相邻边垂直
inline bool Rectangle::check() {
    Parallelogram p(*this);
    if (!p.check()) return false;
    return ((c1 ^ c2) == 0);
}

//构造函数
inline Rectangle::Rectangle(Quadrilateral px) :Parallelogram(px) {
}

//正方形判断:先判断矩形,然后判断邻边相等(注意长度平方避免出现浮点数)
inline bool Square::check() {
    Rectangle p(*this);
    if (!p.check()) return false;
    return c1.len2() == c2.len2();
}

//构造函数
inline Square::Square(Quadrilateral px) :Rectangle(px) {
}

int main()
{
    Quadrilateral a;
    cin >> a;
    cout << fixed << setprecision(2) << a.getPerimeter();
    cout << ' ';
    cout << a.getArea2() << endl;

    Trapezoid tr(a);
    if (tr.check()) cout << "YES\n";
    else cout << "NO\n";

    //套娃警告
    Parallelogram par(a);
    if (par.check())
    {
        Rectangle rec(par);
        if (rec.check())
        {
            Square sq(rec);
            if (sq.check()) cout << "square";
            else cout << "rectangle";
        }
        else cout << "parallelogram";
    }
    else cout << "NO";
}