#include <iostream>
#include <numeric>
using namespace std;

class Fraction
{
    int num, den;

public:
    Fraction(int n = 0, int d = 1)
    {
        int g = gcd(n, d);
        num = n / g;
        den = d / g;
    }

    friend istream& operator>>(istream& in, Fraction& f)
    {
        in >> f.num >> f.den;
        int g = gcd(f.num, f.den);
        f.num /= g;
        f.den /= g;
        return in;
    }

    friend ostream& operator<<(ostream& out, Fraction f)
    {
        out << f.num << "/" << f.den;
        return out;
    }
};

int main()
{
    Fraction f;

    cout << "Enter numerator and denominator: ";
    cin >> f;

    cout << "Simplified fraction: " << f << endl;

    return 0;
}