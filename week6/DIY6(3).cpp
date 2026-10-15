#include <iostream>
#include <stdexcept>
using namespace std;

class SafeArray
{
    int *a, size;

public:
    SafeArray(int n)
    {
        size = n;
        a = new int[size]{};
    }

    int& operator[](int i)
    {
        if (i < 0 || i >= size)
            throw out_of_range("Invalid index");

        return a[i];
    }

    ~SafeArray()
    {
        delete[] a;
    }
};

int main()
{
    SafeArray a(3);

    a[0] = 10;
    a[1] = 20;
    a[2] = 30;

    try
    {
        cout << a[1] << endl;
        cout << a[5] << endl;
    }
    catch (out_of_range& e)
    {
        cout << e.what() << endl;
    }

    return 0;
}