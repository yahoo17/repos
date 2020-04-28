// ConsoleApplication11.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;
int func(int N)
{
    if (N <= 2)
        return N;
    
    else
        return func(N - 1) + func(N - 2);
}
int main()
{
    int N;
    while (cin >> N)
    {
        cout << func(N)<<endl;
    }
}

