
#include <iostream>
#include <memory>
using namespace std;

class Student {
public:
    string name;

    Student(string n) {
        name = n;
    }

    void display() {
        cout << "Student Name: " << name << endl;
    }
};

int main() {
    unique_ptr<Student> s = make_unique<Student>("Shreya");

    s->display();

    cout << "Memory managed automatically." << endl;

    return 0;
}
