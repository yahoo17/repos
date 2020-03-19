#ifndef  DATEANDTIME_H  
#define DATEANDTIME_H  

class DateAndTime
{
public:
    explicit DateAndTime(int = 0, int = 0, int = 0, int = 1, int = 1, int = 2000);

    void setTime(int, int, int);
    void setHour(int);
    void setMinute(int);
    void setSecond(int);

    void tick();

    unsigned int getHour()const;
    unsigned int getMinute()const;
    unsigned int getSecond()const;

    void printUniversal()const;
    void printStandard()const;

private:
    unsigned int hour;
    unsigned int minute;
    unsigned int second;
    unsigned int month;
    unsigned int day;
    unsigned int year;
};
#endif  
#pragma once
