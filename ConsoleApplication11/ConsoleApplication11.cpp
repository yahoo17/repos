// ConsoleApplication11.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;
class A
{

public:
    double a;
    char b;
    int c;
    char* t;
};
int main()
{
    A a;
    cout << sizeof(a);
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单