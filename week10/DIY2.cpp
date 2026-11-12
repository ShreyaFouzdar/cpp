
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream in("in.txt");
    ofstream out("out.txt");

    if (!in || !out) {
        cout << "File error";
        return 0;
    }

    string line;
    int number = 1;

    while (getline(in, line)) {
        out << number << ". " << line << endl;
        number++;
    }

    in.close();
    out.close();

    cout << "File copied successfully.";

    return 0;
}
