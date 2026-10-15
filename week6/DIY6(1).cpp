#include <iostream>
using namespace std;

class Money
{
    int rupees, paise;

public:
    Money(int r, int p)
    {
        rupees = r + p / 100;
        paise = p % 100;
    }

    Money operator+(Money m)
    {
        return Money(rupees + m.rupees, paise + m.paise);
    }

    Money operator-(Money m)
    {
        return Money(rupees - m.rupees, paise - m.paise);
    }

    void display()
    {
        cout << rupees << " rupees " << paise << " paise" << endl;
    }
};

int main()
{
    Money m1(10, 80), m2(5, 50);

    cout << "Addition: ";
    (m1 + m2).display();

    cout << "Subtraction: ";
    (m1 - m2).display();

    return 0;
}