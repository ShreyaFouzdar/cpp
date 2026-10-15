#include <iostream>
using namespace std;

class Shape
{
protected:
    string color;

public:
    Shape(string c) : color(c)
    {
        cout << "Shape constructor" << endl;
    }
};

class Polygon : public Shape
{
protected:
    int sides;

public:
    Polygon(string c, int s) : Shape(c), sides(s)
    {
        cout << "Polygon constructor" << endl;
    }
};

class Rectangle : public Polygon
{
    int length, width;

public:
    Rectangle(string c, int s, int l, int w)
        : Polygon(c, s), length(l), width(w)
    {
        cout << "Rectangle constructor" << endl;
    }

    void display()
    {
        cout << "Color: " << color << endl;
        cout << "Sides: " << sides << endl;
        cout << "Length: " << length << endl;
        cout << "Width: " << width << endl;
    }
};

int main()
{
    Rectangle r("Red", 4, 5, 3);
    r.display();

    return 0;
}