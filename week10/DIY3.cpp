
#include <iostream>
#include <fstream>
using namespace std;

class Student {
public:
    string name;
    int marks;
};

int main() {
    Student s[3];

    ofstream out("students.txt");

    out << "Anu 85\n";
    out << "Ravi 95\n";
    out << "Meera 90\n";

    out.close();

    ifstream in("students.txt");

    for (int i = 0; i < 3; i++) {
        in >> s[i].name >> s[i].marks;
    }

    in.close();

    int topper = 0;

    for (int i = 1; i < 3; i++) {
        if (s[i].marks > s[topper].marks) {
            topper = i;
        }
    }

    cout << "Topper: " << s[topper].name << endl;
    cout << "Marks: " << s[topper].marks << endl;

    return 0;
}
