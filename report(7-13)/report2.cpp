#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <stdexcept>
#include <limits>
using namespace std;

template <class T>
void showMessage(T message)
{
    cout << message << endl;
}

class Student
{
protected:
    string name;
    string usn;

public:
    Student(string n, string u)
    {
        name = n;
        usn = u;
    }

    virtual void display() const
    {
        cout << "Name: " << name << endl;
        cout << "USN: " << usn << endl;
    }

    virtual ~Student() {}
};

class Result : public Student
{
private:
    int marks[3];

public:
    Result(string n, string u, int m1, int m2, int m3)
        : Student(n, u)
    {
        int temp[3] = {m1, m2, m3};

        for (int i = 0; i < 3; i++)
        {
            if (temp[i] < 0 || temp[i] > 100)
                throw out_of_range("Marks must be between 0 and 100.");

            marks[i] = temp[i];
        }
    }

    int getTotal() const
    {
        return marks[0] + marks[1] + marks[2];
    }

    bool isPass() const
{
    return marks[0] >= 35 &&
           marks[1] >= 35 &&
           marks[2] >= 35;
}

    void display() const override
    {
        Student::display();

        cout << "Subject 1: " << marks[0] << endl;
        cout << "Subject 2: " << marks[1] << endl;
        cout << "Subject 3: " << marks[2] << endl;
        cout << "Total Marks: " << getTotal() << "/300" << endl;
        cout << "Result: " << (isPass() ? "PASS" : "FAIL") << endl;
        cout << "--------------------------" << endl;
    }
    void saveToFile(ofstream &file) const
    {
        file << name << "|" << usn << "|"
             << marks[0] << "|" << marks[1] << "|"
             << marks[2] << endl;
    }
};

void displayStudent(const Student &s)
{
    s.display();
}

int readInteger(string message, int minimum, int maximum)
{
    int value;

    while (true)
    {
        cout << message;

        try
        {
            if (!(cin >> value))
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw invalid_argument("Enter a valid number.");
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            if (value < minimum || value > maximum)
                throw out_of_range("Value is outside the allowed range.");

            return value;
        }
        catch (const exception &e)
        {
            cout << "Error: " << e.what() << endl;
        }
    }
}

void addStudent(vector<Result> &students)
{
    string name, usn;

    cout << "Enter Student Name: ";
    getline(cin, name);

    cout << "Enter USN: ";
    getline(cin, usn);

    if (name.empty() || usn.empty())
    {
        showMessage("Name and USN cannot be empty.");
        return;
    }

    try
    {
        int m1 = readInteger("Enter Subject 1 marks (0-100): ", 0, 100);
        int m2 = readInteger("Enter Subject 2 marks (0-100): ", 0, 100);
        int m3 = readInteger("Enter Subject 3 marks (0-100): ", 0, 100);

        students.push_back(Result(name, usn, m1, m2, m3));

        showMessage("Student record added successfully.");
    }
    catch (const exception &e)
    {
        cout << "Error: " << e.what() << endl;
    }
}

void displayAll(const vector<Result> &students)
{
    if (students.empty())
    {
        showMessage("No student records available.");
        return;
    }

    for (const Result &s : students)
    {
        displayStudent(s);
    }
}

void saveRecords(const vector<Result> &students)
{
    ofstream file("students.txt");

    if (!file)
    {
        showMessage("Unable to open file for saving.");
        return;
    }

    for (const Result &s : students)
    {
        s.saveToFile(file);
    }

    file.close();
    showMessage("Records saved successfully.");
}

int convertToInteger(const string &value)
{
    size_t position;
    int number = stoi(value, &position);

    if (position != value.length())
        throw invalid_argument("Invalid mark in file.");

    return number;
}

void loadRecords(vector<Result> &students)
{
    ifstream file("students.txt");

    if (!file)
    {
        showMessage("No saved records found.");
        return;
    }

    vector<Result> loadedStudents;
    string line;

    while (getline(file, line))
    {
        try
        {
            stringstream ss(line);
            string name, usn, m1, m2, m3, extra;

            getline(ss, name, '|');
            getline(ss, usn, '|');
            getline(ss, m1, '|');
            getline(ss, m2, '|');
            getline(ss, m3, '|');

            if (name.empty() || usn.empty() ||
                m1.empty() || m2.empty() || m3.empty() ||
                getline(ss, extra, '|'))
            {
                throw invalid_argument("Invalid student record.");
            }

            loadedStudents.push_back(
                Result(name, usn,
                       convertToInteger(m1),
                       convertToInteger(m2),
                       convertToInteger(m3))
            );
        }
        catch (const exception &e)
        {
            cout << "Invalid record skipped: " << e.what() << endl;
        }
    }

    file.close();
    students = loadedStudents;

    cout << loadedStudents.size()
         << " student record(s) loaded successfully." << endl;
}

void filterStudents(const vector<Result> &students)
{
    int limit = readInteger(
        "Enter minimum total marks (0-300): ", 0, 300
    );

    vector<Result> filteredStudents;

    copy_if(students.begin(), students.end(),
            back_inserter(filteredStudents),
            [limit](const Result &s)
            {
                return s.getTotal() > limit;
            });

    cout << "\nStudents scoring above " << limit << ":\n";

    if (filteredStudents.empty())
    {
        showMessage("No matching students found.");
        return;
    }

    for (const Result &s : filteredStudents)
    {
        displayStudent(s);
    }
}

int main()
{
    vector<Result> students;
    int choice;

    loadRecords(students);

    do
    {
        cout << "\n===== STUDENT RESULT MANAGEMENT SYSTEM =====\n";
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Filter Students\n";
        cout << "4. Save Records\n";
        cout << "5. Load Records\n";
        cout << "6. Exit\n";

        choice = readInteger("Enter your choice: ", 1, 6);

        switch (choice)
        {
        case 1:
            addStudent(students);
            break;

        case 2:
            displayAll(students);
            break;

        case 3:
            filterStudents(students);
            break;

        case 4:
            saveRecords(students);
            break;

        case 5:
            loadRecords(students);
            break;

        case 6:
            showMessage("Exiting program.");
            break;
        }

    } while (choice != 6);

    return 0;
}
