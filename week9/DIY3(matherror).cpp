
#include <iostream>
using namespace std;

class MathError {
};

class DivideByZero : public MathError {
};

int main() {
    try {
        throw DivideByZero();
    }
    catch (MathError& e) {
        cout << "Math Error caught" << endl;
    }
    catch (DivideByZero& e) {
        cout << "Divide By Zero caught" << endl;
    }

    return 0;
}
