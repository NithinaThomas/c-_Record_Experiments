#include <iostream>
using namespace std;

class Shape
{
public:
    virtual float area() = 0;
};

class Circle : public Shape
{
    float radius;

public:
    Circle(float r)
    {
        radius = r;
    }

    float area()
    {
        return 3.14 * radius * radius;
    }
};

class Rectangle : public Shape
{
    float length, breadth;

public:
    Rectangle(float l, float b)
    {
        length = l;
        breadth = b;
    }

    float area()
    {
        return length * breadth;
    }
};

class Triangle : public Shape
{
    float base, height;

public:
    Triangle(float b, float h)
    {
        base = b;
        height = h;
    }

    float area()
    {
        return 0.5 * base * height;
    }
};

// Modified Class
class Square : public Shape
{
    float side;

public:
    Square(float s)
    {
        side = s;
    }

    float area()
    {
        return side * side;
    }
};

int main()
{
    Circle c(10);
    Rectangle r(8, 12);
    Triangle t(15, 12);
    Square s(8);

    Shape *ptr;

    ptr = &c;
    cout << "Area of Circle: " << ptr->area() << endl;

    ptr = &r;
    cout << "Area of Rectangle: " << ptr->area() << endl;

    ptr = &t;
    cout << "Area of Triangle: " << ptr->area() << endl;

    ptr = &s;
    cout << "Area of Square: " << ptr->area() << endl;

    return 0;
}