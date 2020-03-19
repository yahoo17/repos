#include"HughInteger.h"  
#include<iostream>  
using namespace std;

HughInteger::HughInteger(string s = "0") {
    for (int i = 0; i < 80; i++)num[i] = 0;//³õÊ¼»¯  
    input(s);

}

void HughInteger::input(string s) {
    length = 0;
    for (int i = s.size() - 1; i >= 0; i--)
        num[length++] = s[i] - 48;
    length--;
}

void HughInteger::output() {
    bool flag = true;
    for (int i = 39; i >= 0; i--)
    {
        if (num[i] != 0) {
            flag = false;
            cout << num[i];
        }
        else {
            if (!flag)cout << num[i];
        }
    }
}

HughInteger& HughInteger::add(HughInteger b) {
    bool overflow = false;
    HughInteger c;
    for (int i = 0; i < 80; i++) {
        int temp = num[i] + b.num[i] + (overflow ? 1 : 0);
        if (temp >= 10) overflow = true;
        else overflow = false;
        c.num[i] = temp % 10;
    }

    for (int i = 0; i < 80; i++)
        num[i] = c.num[i];
    return *this;
}

HughInteger& HughInteger::subtract(HughInteger b) {
    bool borrow;
    HughInteger c;
    for (int i = 0; i < 39; i++) {
        if (num[i] < b.num[i]) borrow = true;
        else borrow = false;

        if (borrow) num[i + 1]--;

        c.num[i] = num[i] + (borrow ? 10 : 0) - b.num[i];
    }

    for (int i = 0; i < 39; i++)
        num[i] = c.num[i];
    return  *this;
}

HughInteger& HughInteger::operator-(const HughInteger& c2)
{
    return this->subtract(c2);
}

HughInteger& HughInteger::operator*(const HughInteger& c2)
{
    HughInteger c;
    for (int i = 0; i < 80; i++)
        c.num[i] = this->num[i];
    for (int i = 0; i < 40; i++)
    {
        if (num[i] == 0)
            continue;
        else
        {
            for (int i = 0; i < num[i]; i++)
                c.add(c2);
        }
    }
    return c;
}

HughInteger& HughInteger::operator+(const HughInteger& c2)
{
    return this->add(c2);
}

bool HughInteger::isEqualTo(HughInteger b) {
    if (length != b.length)
        return false;

    bool ret = true;
    for (int i = 0; i < 40; i++)
        if (num[i] != b.num[i]) {
            ret = false;
            break;
        }
    return ret;
}

bool HughInteger::isNotEqualTo(HughInteger b) {
    return !isEqualTo(b);
}

bool HughInteger::isGreatThan(HughInteger b) {
    if (length > b.length)return true;
    if (length < b.length)return false;

    for (int i = 39; i > 0; i--) {
        if (num[i] != b.num[i])
            return num[i] > b.num[i];
        else continue;
    }

    return false;
}

bool HughInteger::isLessThanOrRqualTo(HughInteger b) {
    return !isGreatThan(b);
}

bool HughInteger::isLessThan(HughInteger b) {
    if (length > b.length)return false;
    if (length < b.length)return true;

    for (int i = 39; i > 0; i--) {
        if (num[i] != b.num[i])
            return num[i] < b.num[i];
        else continue;
    }

    return false;
}

bool HughInteger::isGreatThanOrEqualTo(HughInteger b) {
    return !isLessThan(b);
}

bool HughInteger::isZero() {
    for (int i = 0; i < 39; i++)
        if (num[i] != 0)return false;

    return true;
}
