#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class Queue {
private:
    vector<T> items;
    int front;
    int rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    bool isFull() {
        return false;
    }

    bool isEmpty() {
        return items.empty();
    }

    void enqueue(T element) {
        if (isFull()) {
            cout << "Queue is full\n";
        } else {
            if (front == -1) front = 0;
            rear++;
            items.push_back(element);
            cout << "Inserted " << element << endl;
        }
    }

    T dequeue() {
        T element;
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return T(); // return default value for T
        } else {
            element = items[front];
            items.erase(items.begin());
            rear--;
            if (items.empty()) {
                front = -1;
                rear = -1;
            }
            cout << "Deleted -> " << element << endl;
            return (element);
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Empty Queue\n";
        } else {
            cout << "Front index-> " << front;
            cout << "Rear index-> " << rear << endl;
            cout << "Items -> ";
            for (int i = 0; i <= rear; i++)
                cout << items[i] << " ";
            cout << endl;
        }
    }
};
