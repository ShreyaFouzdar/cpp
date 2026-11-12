
#include <iostream>
#include <exception>
using namespace std;

class InsufficientFunds : public exception {
public:
    const char* what() const noexcept {
        return "Insufficient balance!";
    }
};

class BankAccount {
    double balance;

public:
    BankAccount(double b) {
        balance = b;
    }

    void withdraw(double amount) {
        if (amount > balance) {
            throw InsufficientFunds();
        }

        balance = balance - amount;

        cout << "Withdrawal successful!" << endl;
        cout << "Remaining balance: " << balance << endl;
    }
};

int main() {
    BankAccount account(5000);

    try {
        account.withdraw(6000);
    }
    catch (InsufficientFunds& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}
