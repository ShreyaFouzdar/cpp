
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream file("nums.txt");

    if (!file) {
        cout << "File not found";
        return 0;
    }

    int num, count = 0, sum = 0;
    int min, max;

    while (file >> num) {
        if (count == 0) {
            min = max = num;
        }

        if (num < min)
            min = num;

        if (num > max)
            max = num;

        sum += num;
        count++;
    }

    file.close();

    cout << "Count: " << count << endl;
    cout << "Sum: " << sum << endl;

    if (count > 0) {
        cout << "Minimum: " << min << endl;
        cout << "Maximum: " << max << endl;
    }

    return 0;
}
