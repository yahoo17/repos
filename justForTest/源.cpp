#include<iostream>  
#include<iomanip>  
#include"HughInteger.h"  
using namespace std;
int main() {
    HughInteger a("23123123123");
    HughInteger b("251");
    HughInteger c("333333333333333333333");
    HughInteger d("444444444444444444444");

    cout << "b is: ";
    b.output();
    cout << "\na is: ";
    a.output();
    cout << "\nc is: ";
    c.output();
    cout << "\nd is: ";
    d.output();

    cout << boolalpha;
    cout <<setw(20)<< setfill(' ')<< setfill(' ')<<"\na is EqualTo b is " << a.isEqualTo(b);
    cout <<setw(20)<< setfill(' ')<< "\na is NotEqualTo b is " << a.isNotEqualTo(b);
    cout <<setw(20)<< setfill(' ')<< "\na is GreatThan b is " << a.isGreatThan(b);
    cout <<setw(20)<< setfill(' ')<< "\na is LessThan b is " << a.isLessThan(b);
    cout <<setw(20)<< setfill(' ')<< "\na is GreatThanOrEqualTo b is " << a.isGreatThanOrEqualTo(b);
    cout <<setw(20)<< setfill(' ')<< "\na is LessThanOrEqualTo b is " << a.isLessThanOrRqualTo(b);
    cout <<setw(20)<< setfill(' ')<< "\n a is Zero is " << a.isZero();

    cout << "\na + b is ";
    a.add(b);
    a.output();

    cout << "\nd - c is ";
    d.subtract(c);
    d.output();



}
