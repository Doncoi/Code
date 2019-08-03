#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

class Shape
{

}; 

class Circle : public Shape
{
private:
    double radius;
    const double PIE = 3.14;
public:
    Circle(double _radius) : radius(_radius)
    {

    };

    void getArea()
    {
        cout << "The area of the Circle is " << radius * radius * PIE << endl;
    }
};

class Rectangle : public Shape
{
private:
    double radius_a;
    double radius_b;
public:
    Rectangle(double _radius_a, double _radius_b) : 
        radius_a(_radius_a), radius_b(_radius_b)
    {

    };

    double extendArea()
    {
        return radius_a * radius_b;
    }

    void getArea()
    {
        cout << "The area of the Rectangle is " << radius_a * radius_b << endl;
    }
};

class Square : public Rectangle
{
public:
    Square(double _radius) : Rectangle::Rectangle(_radius, _radius)
    {

    };

    void getArea()
    {
        cout << "The area of the Square is " << Rectangle::extendArea() << endl;
    }
};

int main()

{

    Circle c(5);

    c.getArea();

    Rectangle r(4,6);

    r.getArea();

    Square s(5);

    s.getArea();

    return 0;

}
