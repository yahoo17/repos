// 姓名:严灏 序号1 学号 201830020446
//友元函数重载 输入输出符
#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

class Date
{
   
private:
    int year, month, day;
public:
    Date(int year = 2000, int month = 1, int day = 1) :year(year), month(month), day(day) {}
    friend istream& operator>>(istream& c, Date& px);
    friend ostream& operator<<(ostream& c, Date px);
};
istream& operator>>(istream& c, Date& px)
{
    c >> px.year >> px.month >> px.day;
    return c;
}

ostream& operator<<(ostream& c, Date px)
{
    //日期格式
    c << px.year << '-' << setw(2) << setfill('0') << px.month << '-' << setw(2) << px.day;
    return c;
}

//判断质数
bool IsPrime(int x)
{
    if (x == 1) 
        return false;
    int i;
    for (i = 2; i * i <= x; i++)
    {
        if (x % i == 0) 
            return false;
    }
    return true;
}
int main()
{
   
    Date da;
    cin >> da;
    cout << da << endl;
    
    int count;
    cin >> count;
    for (int i = 1; i <= count; i++)
    {
        int mid = (count + 1) / 2;
        int left = abs(i - mid) + 1;//左边星号位置
        int right = 2 * mid - left;//右边星号位置
        cout << setw(left) << setfill(' ') << '*';//输出左边星号
        if (right > left) cout << setw(right - left) << '*';//输出右边星号
        cout << endl;
    }
    
    int prec;
    double val;
    cin >> prec >> val;
    cout.unsetf(ios::fixed);
    cout << setprecision(prec) << showpoint << val << endl;
    
    double sc1, sc2;

    cin >> scientific >> uppercase >> sc1 >> sc2;
    cout << scientific << uppercase << setprecision(5) << sc1 + sc2 << endl;//注意这里6位有效数字是5位小数
    
    int pri;
    cin >> pri;
    cout << boolalpha << IsPrime(pri);
}


