// ConsoleApplication4.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include <cstdio>
using namespace std;

int pow(int b)
{
    int temp = 1;
    for (int i = 0; i < b; i++)
        temp *= 2;
    return temp;
};

int main()
{
    printf("% d", pow(16));
    
    
}
