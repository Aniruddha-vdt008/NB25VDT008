
#include <iostream>
using namespace std;

class Account {
protected:
    double balance;

public:
    Account(double b) {
        balance = b;
    }

    virtual void calculateInterest() = 0;
    virtual ~Account() {}
};

class Savings : public Account {
public:
    Savings(double b) : Account(b) {}

    void calculateInterest() override {
        cout << "Savings Interest: "
             << balance * 0.05 << endl;
    }
};

class Current : public Account {
public:
    Current(double b) : Account(b) {}

    void calculateInterest() override {
        cout << "Current Interest: "
             << balance * 0.02 << endl;
    }
};

int main() {
    Savings s(10000);
    Current c(10000);

    Account* a[] = {&s, &c};

    for (int i = 0; i < 2; i++) {
        a[i]->calculateInterest();
    }

    return 0;
}
