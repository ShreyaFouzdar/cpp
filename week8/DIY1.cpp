
#include <iostream>
using namespace std;

class Account {
public:
    virtual void calculateInterest() = 0;
};

class Savings : public Account {
    float balance;

public:
    Savings(float b) {
        balance = b;
    }

    void calculateInterest() {
        cout << "Savings Interest: " << balance * 0.05 << endl;
    }
};

class Current : public Account {
    float balance;

public:
    Current(float b) {
        balance = b;
    }

    void calculateInterest() {
        cout << "Current Interest: " << balance * 0.02 << endl;
    }
};

int main() {
    Savings s(10000);
    Current c(10000);

    Account* accounts[2];

    accounts[0] = &s;
    accounts[1] = &c;

    for (int i = 0; i < 2; i++) {
        accounts[i]->calculateInterest();
    }

    return 0;
}
