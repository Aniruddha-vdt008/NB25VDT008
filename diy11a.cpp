
#include <iostream>
using namespace std;

template <class T>
void swapVals(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

template <class T>
T findMax(T arr[], int n) {
    T maximum = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] > maximum)
            maximum = arr[i];
    }

    return maximum;
}

int main() {
    int a = 10, b = 20;

    swapVals(a, b);

    cout << "After swapping integers: "
         << a << " " << b << endl;

    int arr1[] = {10, 50, 30, 20};

    cout << "Maximum integer: "
         << findMax(arr1, 4) << endl;

    double arr2[] = {2.5, 8.7, 4.3};

    cout << "Maximum double: "
         << findMax(arr2, 3) << endl;

    return 0;
}
