#include <stdint.h>

#include <iostream>
using namespace std;
// ConsoleApplication5.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
class A
{

public:
    A()
    {
        printf("A constructor\n");

    }
    ~A()
    {
        printf("A destructor\n");
    }
    virtual void print()=0;
};
class B: virtual public A
{
public:
    B() { printf("B constructor\n"); }
    ~B() { printf("B destructor\n"); }


};
class C :public B
{
public:
    C() { printf("C con\n"); }
    ~C() { printf("c des\n"); }
    virtual void print()
    {
        printf(" print function\n");
    }

};


int main()
{
   /* C c;
    c.print();*/
   A * aptr= 0;
   
    aptr = new C();
    aptr->print();
   
}
