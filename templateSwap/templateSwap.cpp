// templateSwap.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
///学号 201830020446 序号1 严灏
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
template <typename Tint>
void Swap(Tint &para1, Tint &para2)
{
    Tint temp = para1;
    para1 = para2;
    para2 = temp;


}
template <typename Tint>
Tint Max(Tint para1, Tint para2)
{
    return para1 > para2?para1 : para2;
}
int main()
{
    int a, b;
    cin >> a >> b;
    double c, d;
    cin >> c >> d;
    string e, f;
    cin >> e >> f;

    cout << Max(a, b) << endl;
    cout << fixed << setprecision(2) << Max(c, d) << endl;
    Swap(e, f);
    cout << e << " " << f << endl;

}
