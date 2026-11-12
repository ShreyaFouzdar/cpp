
#include <iostream>
#include <exception>
using namespace std;

class Overflow : public exception {
public:
    const char* what() const noexcept {
        return "Stack Overflow!";
    }
};

class Underflow : public exception {
public:
    const char* what() const noexcept {
        return "Stack Underflow!";
    }
};

class Stack {
    int arr[3];
    int top;

public:
    Stack() {
        top = -1;
    }

    void push(int value) {
        if (top == 2) {
            throw Overflow();
        }

        arr[++top] = value;
        cout << value << " pushed" << endl;
    }

    void pop() {
        if (top == -1) {
            throw Underflow();
        }

        cout << arr[top--] << " popped" << endl;
    }
};

int main() {
    Stack s;

    try {
        s.push(10);
        s.push(20);
        s.push(30);
        s.push(40);
    }
    catch (Overflow& e) {
        cout << e.what() << endl;
    }

    try {
        s.pop();
        s.pop();
        s.pop();
        s.pop();
    }
    catch (Underflow& e) {
        cout << e.what() << endl;
    }

    return 0;
}
