#include <iostream>
using namespace std;

class Money {
private:
    int rupees, paise;

public:
    Money(int r = 0, int p = 0) {
        int totalPaise = r * 100 + p;
        rupees = totalPaise / 100;
        paise = totalPaise % 100;
    }

    Money operator+(const Money& m) const {
        int total1 = rupees * 100 + paise;
        int total2 = m.rupees * 100 + m.paise;
        int sum = total1 + total2;

        return Money(sum / 100, sum % 100);
    }

    Money operator-(const Money& m) const {
        int total1 = rupees * 100 + paise;
        int total2 = m.rupees * 100 + m.paise;

        if (total1 < total2) {
            cout << "Subtraction would be negative!" << endl;
            return Money();
        }

        int diff = total1 - total2;
        return Money(diff / 100, diff % 100);
    }

    void display() const {
        cout << "Rs. " << rupees << "."
             << (paise < 10 ? "0" : "") << paise << endl;
    }
};

int main() {
    Money m1(10, 75);
    Money m2(5, 50);

    Money sum = m1 + m2;
    Money diff = m1 - m2;

    cout << "First amount: ";
    m1.display();

    cout << "Second amount: ";
    m2.display();

    cout << "Addition: ";
    sum.display();

    cout << "Subtraction: ";
    diff.display();

    return 0;
}