#include <iostream>
using namespace std;

class Matrix {
private:
    int rows, cols;
    int** data;

public:
    // Constructor
    Matrix(int m, int n) {
        rows = m;
        cols = n;

        data = new int*[rows];

        for (int i = 0; i < rows; i++) {
            data[i] = new int[cols]();
        }
    }

    // Deep copy constructor
    Matrix(const Matrix& other) {
        rows = other.rows;
        cols = other.cols;

        data = new int*[rows];

        for (int i = 0; i < rows; i++) {
            data[i] = new int[cols];

            for (int j = 0; j < cols; j++) {
                data[i][j] = other.data[i][j];
            }
        }
    }

    // Read matrix elements
    void input() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cin >> data[i][j];
            }
        }
    }

    // Display matrix
    void display() const {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << data[i][j] << " ";
            }
            cout << endl;
        }
    }

    // Destructor
    ~Matrix() {
        for (int i = 0; i < rows; i++) {
            delete[] data[i];
        }

        delete[] data;
    }
};

int main() {
    Matrix A(2, 2);

    cout << "Enter 4 matrix elements:" << endl;
    A.input();

    cout << "Original Matrix:" << endl;
    A.display();

    Matrix B = A;  // Deep copy

    cout << "Copied Matrix:" << endl;
    B.display();

    return 0;
}