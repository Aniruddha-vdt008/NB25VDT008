
#include <iostream>
#include <exception>
using namespace std;

class MathError : public exception {
public:
    const char* what() const noexcept override {
        return "Mathematical error!";
    }
};

class DivideByZero : public MathError {
public:
    const char* what() const noexcept override {
        return "Division by zero!";
    }
};

int main() {
    try {
        throw DivideByZero();
    }
    catch (const DivideByZero& e) {
        cout << "Derived exception: " << e.what() << endl;
    }
    catch (const MathError& e) {
        cout << "Base exception: " << e.what() << endl;
    }

    return 0;
}
