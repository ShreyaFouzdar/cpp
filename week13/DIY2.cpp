
#include <iostream>
#include <vector>
#include <memory>
using namespace std;

class Shape {
public:
    virtual void area() = 0;
    virtual ~Shape() {}
};

class Circle : public Shape {
public:
    void area() {
        cout << "Area of Circle = " << 3.14 * 5 * 5 << endl;
    }
};

class Rectangle : public Shape {
public:
    void area() {
        cout << "Area of Rectangle = " << 10 * 5 << endl;
    }
};

class Triangle : public Shape {
public:
    void area() {
        cout << "Area of Triangle = " << 0.5 * 10 * 5 << endl;
    }
};

int main() {
    vector<unique_ptr<Shape>> shapes;

    string name;

    cout << "Enter shape (circle/rectangle/triangle): ";
    cin >> name;

    if (name == "circle") {
        shapes.push_back(make_unique<Circle>());
    }
    else if (name == "rectangle") {
        shapes.push_back(make_unique<Rectangle>());
    }
    else if (name == "triangle") {
        shapes.push_back(make_unique<Triangle>());
    }
    else {
        cout << "Invalid shape";
        return 0;
    }

    for (auto &s : shapes) {
        s->area();
    }

    return 0;
}
