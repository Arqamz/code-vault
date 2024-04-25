#include <iostream>

using namespace std;

class ArrayStack {
private:
    int topIndex;
    int capacity;
    int* stackArray;

public:
    ArrayStack(int size) {
        topIndex = -1;
        capacity = size;
        stackArray = new int[size];
    }

    ~ArrayStack() {
        delete[] stackArray;
    }

    void push(int data) {
        if (topIndex == capacity - 1) {
            cout << "Stack is full\n";
            return;
        }
        stackArray[++topIndex] = data;
    }

    void pop() {
        if (topIndex == -1) {
            cout << "Stack is empty\n";
            return;
        }
        topIndex--;
    }

    int top() {
        if (topIndex == -1) {
            cout << "Stack is empty\n";
            return -1;
        }
        return stackArray[topIndex];
    }

    bool empty() {
        return topIndex == -1;
    }
};

int main() {
    ArrayStack s(3);
    s.push(1);
    s.push(2);
    s.push(3);
    cout << s.top() << "\n"; // prints 3
    s.pop();
    cout << s.top() << "\n"; // prints 2
    return 0;
}