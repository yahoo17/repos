#include<iostream>  
#include"Date.h"  
#include<stdexcept>  
using namespace std;
Date::Date(int m, int d, int y) {
    if (m > 0 && m < 13)
        month = m;
    else throw invalid_argument("month must be 1-12");

    if (d > 0 && d <= 30)
        day = d;
    else throw invalid_argument("day must be 1-30");

    if (y > 0)
        year = y;
    else throw invalid_argument("year must be >0");
}

void Date::print() {
    cout << month << "/" << day << "/" << year;
}

void Date::nextDay() {
    bool monthFlag = false;
    if (day == 30) {
        monthFlag = true;
        day = 1;
    }
    else day++;

    if (monthFlag) {
        if (month == 12) {
            month = 1;
            year++;
        }
        else month++;
    }
}
