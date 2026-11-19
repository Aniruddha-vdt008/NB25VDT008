
#include <iostream>
#include <exception>
using namespace std;

class InsufficientFunds : public exception {
public:
    const char* what() const noexcept override {
        return "Insufficient balance!";
    }
};

class BankAccount {
    double balance;

public:
    BankAccount(double b) : balance(b) {}

    void withdraw(double amount) {
        if (amount > balance)
            throw InsufficientFunds();

        balance -= amount;
        cout << "Withdrawal successful!\n";
        cout << "Remaining balance: " << balance << endl;
    }
};

int main() {
    BankAccount account(5000);

    try {
        account.withdraw(2000);
        account.withdraw(4000);
    }
    catch (const InsufficientFunds& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}
