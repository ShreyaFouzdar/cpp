#include <iostream>
using namespace std;

double volume(double a)
{
    return a * a * a;
}

double volume(double l, double b, double h)
{
    return l * b * h;
}

double volume(double r, double h)
{
    return 3.14159 * r * r * h;
}

int main()
{
    cout << "Cube = " << volume(3) << endl;
    cout << "Cuboid = " << volume(2, 3, 4) << endl;
    cout << "Cylinder = " << volume(2, 5) << endl;

    return 0;
}