
#include <iostream>
#include <fstream>
using namespace std;

class Logger {
public:
    virtual void write(string message) = 0;
};

class ConsoleLogger : public Logger {
public:
    void write(string message) {
        cout << "Console: " << message << endl;
    }
};

class FileLogger : public Logger {
public:
    void write(string message) {
        ofstream file("log.txt");

        file << message;

        file.close();

        cout << "Message written to file." << endl;
    }
};

int main() {
    Logger* logger;

    ConsoleLogger c;
    FileLogger f;

    int choice;

    cout << "1. Console Logger" << endl;
    cout << "2. File Logger" << endl;
    cout << "Enter choice: ";
    cin >> choice;

    cin.ignore();

    string message;

    cout << "Enter message: ";
    getline(cin, message);

    if (choice == 1) {
        logger = &c;
    }
    else if (choice == 2) {
        logger = &f;
    }
    else {
        cout << "Invalid choice";
        return 0;
    }

    logger->write(message);

    return 0;
}
