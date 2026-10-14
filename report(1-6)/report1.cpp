#include <iostream>
#include <string>
using namespace std;

class Student 
{
    private:
    string name;
    int marks;
    static int count;

    public:
    // Parameterized constructor
     Student(string n, int m)
    {
        name = n;
        marks = m;
        count++;
     }

    // Function overloading
    void display() 
   {
        cout << "Name: " << name << endl;
        cout << "Marks: " << marks << endl;
    }

    void display(string title)
   {
        cout << title << endl;
        display();
    }

    // Static member function
    static void showCount() 
  {
        cout << "Total students: " << count << endl;
    }

    // Friend function
    friend void showStudent(const Student& s);

    // Operator overloading
    bool operator>(const Student& s) const 
   {
        return marks > s.marks;
    }
};

// Definition of static data member
int Student::count = 0;

// Definition of friend function
void showStudent(const Student& s) 
{
    cout << "Friend function: " << s.name << ", Marks: " << s.marks << endl;
}

int main() 
{
    Student s1("Anu", 85);
    Student s2("Riya", 92);

    cout << "Student 1:" << endl;
    s1.display();

    cout << "\nStudent 2:" << endl;
    s2.display("Student Details:");

    cout << endl;
    showStudent(s1);

    Student::showCount();

    if (s1 > s2)
        cout << "Anu has higher marks." << endl;
    else
        cout << "Riya has higher marks." << endl;

    return 0;
}
