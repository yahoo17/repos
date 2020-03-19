#include<iostream>  
#include<iomanip>  
#include<stdexcept>  
#include"DateAndTime.h";  
using namespace std;

DateAndTime::DateAndTime(int hour, int minute, int second, int month1, int day1, int year1) {
    setTime(hour, minute, second);
    month = month1;
    day = day1;
    year = year1;
}

void DateAndTime::setTime(int h, int m, int s) {
    setHour(h);
    setMinute(m);
    setSecond(s);
}

void DateAndTime::setHour(int h) {
    if (h >= 0 && h < 24)
        hour = h;
    else throw invalid_argument("hour must be 0-23");
}

void DateAndTime::setMinute(int m) {
    if (m >= 0 && m < 60)
        minute = m;
    else throw invalid_argument("minute must be 0-59");
}

void DateAndTime::setSecond(int s) {
    if (s >= 0 && s < 60)
        second = s;
    else throw invalid_argument("second must be 0-59");
}

void DateAndTime::tick() {
    bool minuteFlag = false;
    bool hourFlag = false;
    bool dayFlag = false;
    bool monthFlag = false;

    if (second == 59) {
        second = 0;
        minuteFlag = true;
    }
    else second++;

    if (minuteFlag) {
        if (minute == 59) {
            minute = 0;
            hourFlag = true;
        }
        else minute++;
    }

    if (hourFlag) {
        if (hour == 23) {
            hour = 0;
            dayFlag = true;
        }
        else hour++;
    }

    if (dayFlag) {
        if (day == 30) {
            monthFlag = true;
            day = 1;
        }
        else day++;
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

unsigned int DateAndTime::getHour()const {
    return hour;
}

unsigned int DateAndTime::getMinute()const {
    return minute;
}

unsigned int DateAndTime::getSecond()const {
    return second;
}

void DateAndTime::printUniversal()const {
    cout << setfill('0') << setw(2) << getHour() << ":" <<
        setw(2) << getMinute() << ":" << setw(2) << getSecond();
}

void DateAndTime::printStandard()const {
    cout << ((getHour() == 0 || getHour() == 12) ? 12 : getHour() % 12)
        << ":" << setfill('0') << setw(2) << getMinute()
        << ":" << setw(2) << getSecond() << (hour > 12 ? "PM" : "AM");
    cout << "  ";
    cout << month << "/" << day << "/" << year;
}
