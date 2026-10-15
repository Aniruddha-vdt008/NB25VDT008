#include <iostream>
#include <stdexcept>
using namespace std;

class SafeArray {
private:
    int* arr;
    int size;

public:
    SafeArray(int n) {
        if (n <= 0) {
            throw invalid_argument("Size must be positive");
        }

        size = n;
        arr = new int[size]();
    }

    // Disable shallow copying
    SafeArray(const SafeArray&) = delete;
    SafeArray& operator=(const SafeArray&) = delete;

    int& operator[](int index) {
        if (index < 0 || index >= size) {
            throw out_of_range("Array index out of range");
        }

        return arr[index];
    }

    ~SafeArray() {
        delete[] arr;
    }
};

int main() {
    try {
        SafeArray a(5);

        for (int i = 0; i < 5; i++) {
            a[i] = (i + 1) * 10;
        }

        cout << "Array elements: ";

        for (int i = 0; i < 5; i++) {
            cout << a[i] << " ";
        }

        cout << endl;

        cout << "Accessing index 7: " << a[7] << endl;
    }
    catch (const out_of_range& e) {
        cout << "Error: " << e.what() << endl;
    }
    catch (const invalid_argument& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}