//学号 201830020446 姓名 严灏 序号1
#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
    int base, value;
    while (!(cin >> dec >> base).eof())//注意base的输入是十进制的,而setbase是粘性操作符
    {
        cin >> setbase(base) >> value;
        cout << dec << value << ' ';
        cout << hex << showbase << value << ' ';
        cout << oct << noshowbase << setw(4) << setfill('0') << value << endl;
    }
}