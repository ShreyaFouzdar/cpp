#include <iostream>
using namespace std;

class Person
{
public:
    Person()
    {
        cout << "Person constructor" << endl;
    }
};

class Student : virtual public Person
{
public:
    Student()
    {
        cout << "Student constructor" << endl;
    }
};

class Employee : virtual public Person
{
public:
    Employee()
    {
        cout << "Employee constructor" << endl;
    }
};

class TA : public Student, public Employee
{
public:
    TA()
    {
        cout << "TA constructor" << endl;
    }
};

int main()
{
    TA t;
    return 0;
}