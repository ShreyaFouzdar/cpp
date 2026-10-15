#include <iostream>
using namespace std;

class Tracer
{
    int id;

public:
    Tracer(int x)
    {
        id = x;
        cout << "Created: " << id << endl;
    }

    ~Tracer()
    {
        cout << "Destroyed: " << id << endl;
    }
};

int main()
{
    for (int i = 1; i <= 3; i++)
    {
        Tracer *t = new Tracer(i);
        delete t;
    }

    return 0;
}