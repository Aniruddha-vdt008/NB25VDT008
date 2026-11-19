
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int main() {
    vector<int> v = {2, 4, 6, 8, 10};

    int product = accumulate(
        v.begin(), v.end(), 1,
        [](int a, int b) {
            return a * b;
        }
    );

    int evenSum = accumulate(
        v.begin(), v.end(), 0,
        [](int sum, int x) {
            if (x % 2 == 0)
                return sum + x;

            return sum;
        }
    );

    cout << "Product of elements: "
         << product << endl;

    cout << "Sum of even elements: "
         << evenSum << endl;

    return 0;
}
