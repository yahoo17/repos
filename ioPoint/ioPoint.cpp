// ioPoint.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//各种重载运算符的方式都试了一下 熟悉一下分别用友元函数和类成员函数来重载运算符
//学号201830020446 序号1 姓名严灏

#include <iostream>
using namespace std;
class Point
{
public:
    bool cinok; //用来判断是否正常输入
public:
    Point():x(0),y(0),cinok(false){}
public:
    int x;
    int y;

public:
    friend ostream& operator<<(ostream& os, const Point p1); \
    friend istream& operator>>(istream& is, Point &p1);
    Point operator+(const Point p2);

};
istream& operator>>(istream& is, Point &p1)
{
    cin.clear();
    is >> p1.x;
    is>> p1.y;
    p1.cinok = cin.fail();
    if ((p1.x < -1000) || (p1.x>1000) || (p1.y < -1000) | (p1.y>1000))
        p1.cinok = true;
    return is;
}
Point Point::operator+(const Point p2)
{
    Point temp;

    temp.x = this->x + p2.x;
    temp.y = this->y + p2.y;
    if (this->cinok == true || p2.cinok == true)
        temp.cinok = true;
    return temp;
}
ostream& operator<< (ostream & os, const Point p1)
{
    if (p1.cinok == false)
        os << "(" << p1.x << ',' << p1.y << ')' << endl;
    else
        os << "Invaild input."<<endl;
    return os; 

}
int main()
{
    Point pa, pb;
    while (!(cin >> pa >> pb).eof())
    {
        if (cin.fail()) {
            cout << "Invaild input." << endl;
            cin.clear();
            //忽略这一行后面的数据
            cin.ignore(100, '\n');
        }
        else
        {
            cout << pa + pb << endl;
        }
    }
}
