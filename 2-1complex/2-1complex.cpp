// 2-1complex.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "complex.h"
using namespace std;

int main()
{
    int a, b, c, d;
    cin >> a >> b;
    complex c1(a, b);
    cin >> c >> d;
    complex c2(c, d);
    {
        cout << (c1 + c2).m_real << "+";
        if ((c1 + c2).m_image == 1)
            cout << "i" << endl;
        else if ((c1 + c2).m_image == -1)
            cout << "-i" << endl;
        else
            cout << (c1 + c2).m_image << "i" << endl;

    }
    {
        cout << (c1 - c2).m_real << "+";
        if ((c1 - c2).m_image == 1)
            cout << "i" << endl;
        else if ((c1 - c2).m_image == -1)
            cout << "-i" << endl;
        else
            cout << (c1 - c2).m_image << "i" << endl;

    }
   
    {
        cout << (c1 *c2).m_real << "+";
        if ((c1 * c2).m_image == 1)
            cout << "i" << endl;
        else if ((c1 *c2).m_image == -1)
            cout << "-i" << endl;
        else
            cout << (c1 *c2).m_image << "i" << endl;

    }
  
    if (c1 == c2)
        cout << "a==b" << endl;
    else
        cout << "a!=b" << endl;
    
}
