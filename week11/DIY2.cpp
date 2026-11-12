
#include <iostream>
#include <string>
using namespace std;

template <class T>
class Queue {
    T arr[5];
    int frontIndex, rear;

public:
    Queue() {
        frontIndex = 0;
        rear = -1;
    }

    void enqueue(T value) {
        if (rear == 4) {
            cout << "Queue is full" << endl;
            return;
        }

        arr[++rear] = value;
    }

    void dequeue() {
        if (frontIndex > rear) {
            cout << "Queue is empty" << endl;
            return;
        }

        cout << "Removed: " << arr[frontIndex++] << endl;
    }

    void front() {
        if (frontIndex > rear) {
            cout << "Queue is empty" << endl;
        }
        else {
            cout << "Front: " << arr[frontIndex] << endl;
        }
    }
};

int main() {
    Queue<string> q;

    q.enqueue("Apple");
    q.enqueue("Banana");
    q.enqueue("Mango");

    q.front();

    q.dequeue();

    q.front();

    return 0;
}
