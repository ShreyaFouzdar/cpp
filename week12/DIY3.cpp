
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int main() {
    vector<int> v = {1, 2, 3, 4, 5};

    int product = accumulate(v.begin(), v.end(), 1,
        [](int a, int b) {
            return a * b;
        });

    int evenSum = accumulate(v.begin(), v.end(), 0,
        [](int a, int b) {
            if (b % 2 == 0)
                return a + b;
            else
                return a;
        });

    cout << "Product of all elements: " << product << endl;
    cout << "Sum of even elements: " << evenSum << endl;

    return 0;
}
