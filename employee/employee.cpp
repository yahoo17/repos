// 序号1 严灏 201830020446 
#include <iostream>
#include <vector>
using namespace std;

class DATE
{
public:
    DATE() {};
    DATE(int a, int b, int c):Date(a), Month(b),Year(c)
    {}
    int Date;
    int Month;
    int Year;
    friend istream& operator>>(istream& is,DATE & dt);

};

istream& operator>>(  istream& is, DATE & dt)
{
    is >> dt.Year;
    is >> dt.Month;
    is >> dt.Date;
    return is;
}
class Employee
{
public:
    Employee (DATE da,int base):date(da),base(base){}
    DATE date;
    int base;
    int totalMoney(int month);

};
int Employee::totalMoney(int month)
{
    if (month == date.Month)
        return base + 100;
    return base;
}
int main()
{
    vector<Employee> employee;
    int number;
    cin >> number;
    
    for (int i = 0; i < number; i++)
    {
        DATE date;
        cin >> date;
        int base;
        cin >> base;
        Employee ee(date, base);
        employee.push_back(ee);        
    }
    for (int i = 1; i <= 12; i++)
    {
        for (auto it = employee.begin(); it != employee.end(); it++)
        {
            cout << it->totalMoney(i) << " ";
        }
        cout << endl;
    }
}

