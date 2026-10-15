#include <iostream>
using namespace std;

class Matrix
{
    int **a;
    int m, n;

public:
    Matrix(int r, int c) : m(r), n(c)
    {
        a = new int*[m];

        for (int i = 0; i < m; i++)
            a[i] = new int[n]{};
    }

    Matrix(const Matrix &x) : m(x.m), n(x.n)
    {
        a = new int*[m];

        for (int i = 0; i < m; i++)
        {
            a[i] = new int[n];

            for (int j = 0; j < n; j++)
                a[i][j] = x.a[i][j];
        }
    }

    void set(int i, int j, int value)
    {
        a[i][j] = value;
    }

    void display()
    {
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
                cout << a[i][j] << " ";
            cout << endl;
        }
    }

    ~Matrix()
    {
        for (int i = 0; i < m; i++)
            delete[] a[i];

        delete[] a;
    }
};

int main()
{
    Matrix m1(2, 2);
    m1.set(0, 0, 1);
    m1.set(0, 1, 2);
    m1.set(1, 0, 3);
    m1.set(1, 1, 4);

    Matrix m2 = m1;

    cout << "Copied Matrix:" << endl;
    m2.display();

    return 0;
}