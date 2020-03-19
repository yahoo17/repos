#include<iostream>  
#include<stdexcept>  
#include<algorithm>  
#include"Rectangle.h"  
using namespace std;

double distance(point m, point n) {
    return (m.x - n.x) * (m.x - n.x) + (m.y - n.y) * (m.y - n.y);
}

Rectangle::Rectangle(point a = { 0,0 }, point b = { 0,0 }, point c = { 0,0 }, point d = { 0,0 }) {
    bool isRec;
    point center;
    center.x = (a.x + b.x + c.x + d.x) / 4;
    center.y = (a.y + b.y + c.y + d.y) / 4;
    if (distance(center, a) == distance(center, b) && distance(center, c) == distance(center, d))
        isRec = true;
    else isRec = false;

    if (isRec) {
        double leng1 = max(fabs(a.x - b.x), fabs(a.x - c.x));
        double leng2 = max(fabs(a.y - b.y), fabs(a.y - c.y));

        setLength(max(leng1, leng2));
        setWidth(min(leng1, leng2));

        up = c.y;
        down = a.y;
        left = a.x;
        right = c.x;
    }
    //else throw invalid_argument("this is not a rectangle.");  
}

void Rectangle::setLength(double l) {
    if (l > 0 && l < 20)
        length = l;
    else throw invalid_argument("not allow");
}

void Rectangle::setWidth(double w) {
    if (w > 0 && w < 20)
        width = w;
    else throw invalid_argument("now allow");
}

bool Rectangle::square() {
    if (length == width)return true;
    else return false;
}

double Rectangle::getLegnth()const {
    return length;
}

double Rectangle::getWidth()const {
    return width;
}

void Rectangle::setFillCharacter(char a) {
    body = a;
}

void Rectangle::setPerimeterCharacter(char a) {
    border = a;
}

void Rectangle::draw() {
    for (int i = 25; i > 0; i--) {
        for (int j = 1; j <= 25; j++) {
            if (i <= up && i >= down && j <= right && j >= left) {
                if (i == up || i == down || j == left || j == right)
                    cout << border;
                else cout << body;
            }
            else cout << "0";
        }
        cout << endl;
    }

}

void Rectangle::move(double a, double b) {
    left += a;
    right += a;
    up += b;
    down += b;
}

