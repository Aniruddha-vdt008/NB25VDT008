#include <iostream>
using namespace std;

class Stack {
private:
    int* arr;
    int capacity;
    int top;

public:
    // Constructor
    Stack(int size) {
        capacity = size;
        arr = new int[capacity];
        top = -1;
    }

    // Push element
    void push(int value) {
        if (top == capacity - 1) {
            cout << "Stack Overflow!" << endl;
            return;
        }

        arr[++top] = value;
        cout << value << " pushed" << endl;
    }

    // Pop element
    void pop() {
        if (top == -1) {
            cout << "Stack Underflow!" << endl;
            return;
        }

        cout << arr[top--] << " popped" << endl;
    }

    // Display stack
    void display() const {
        if (top == -1) {
            cout << "Stack is empty" << endl;
            return;
        }

        cout << "Stack elements: ";

        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }

        cout << endl;
    }

    // Destructor
    ~Stack() {
        delete[] arr;
        cout << "Stack memory released" << endl;
    }
};

int main() {
    Stack s(5);

    s.push(10);
    s.push(20);
    s.push(30);

    s.display();

    s.pop();

    s.display();

    return 0;
}