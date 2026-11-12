
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<pair<string, int>> students = {
        {"Anu", 85},
        {"Ravi", 70},
        {"Meera", 95},
        {"Kiran", 80}
    };

    sort(students.begin(), students.end(),
        [](pair<string, int> a, pair<string, int> b) {
            return a.second < b.second;
        });

    cout << "Sorted records:" << endl;

    for (auto p : students) {
        cout << p.first << " " << p.second << endl;
    }

    return 0;
}
