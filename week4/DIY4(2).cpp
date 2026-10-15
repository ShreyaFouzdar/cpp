#include <iostream>
using namespace std;

class Stack
{
    int *a;
    int top, size;

public:
    Stack(int s)
    {
        size = s;
        a = new int[size];
        top = -1;
    }

    void push(int x)
    {
        if (top == size - 1)
            cout << "Stack is full" << endl;
        else
            a[++top] = x;
    }

    void pop()
    {
        if (top == -1)
            cout << "Stack is empty" << endl;
        else
            cout << "Popped: " << a[top--] << endl;
    }

    ~Stack()
    {
        delete[] a;
        cout << "Memory released" << endl;
    }
};

int main()
{
    Stack s(3);

    s.push(10);
    s.push(20);
    s.push(30);

    s.pop();
    s.pop();

    return 0;
}