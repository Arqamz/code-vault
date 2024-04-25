#include <iostream>

using namespace std;

template <typename T>
class ArrayStack {
private:
    int topIndex;
    int capacity;
    T* stackArray;

public:
    ArrayStack(int size) {
        topIndex = -1;
        capacity = size;
        stackArray = new T[size];
    }

    ~ArrayStack() {
        delete[] stackArray;
    }

    void push(T data) {
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

    T top() {
        if (topIndex == -1) {
            cout << "Stack is empty\n";
            return T();
        }
        return stackArray[topIndex];
    }

    bool empty() {
        return topIndex == -1;
    }
};

int main() {
    ArrayStack<int> s(3);
    s.push(1);
    s.push(2);
    s.push(3);
    cout << s.top() << "\n"; // prints 3
    s.pop();
    cout << s.top() << "\n"; // prints 2
    return 0;
}