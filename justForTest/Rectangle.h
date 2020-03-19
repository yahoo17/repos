#ifndef RECTANGLE_H  
#define RECTANGLE_H  
struct point
{
    double x; double y;
};
class Rectangle {
private:
    double length;
    double width;

    char body;
    char border;

    double up, down, left, right;
public:
    Rectangle(point, point, point, point);
    void setLength(double);
    void setWidth(double);
    bool square();
    double getLegnth()const;
    double getWidth()const;

    void setFillCharacter(char);
    void setPerimeterCharacter(char);
    void draw();
    void move(double, double);
};
#endif // !RECTANGLE_H  
