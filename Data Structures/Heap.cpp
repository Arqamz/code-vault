#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

template<typename T>
class MinHeap {
private:
    vector<T> data;

public:
    void push(T val) {
        data.push_back(val);
        int index = data.size() - 1;
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (data[parent] <= data[index]) {
                break;
            }
            swap(data[parent], data[index]);
            index = parent;
        }
    }

    T pop() {
        if (data.empty()) {
            throw runtime_error("Heap is empty");
        }
        T result = data[0];
        int index = 0;
        data[index] = data.back();
        data.pop_back();
        while (true) {
            int left = 2 * index + 1;
            int right = 2 * index + 2;
            int smallest = index;
            if (left < data.size() && data[left] < data[smallest]) {
                smallest = left;
            }
            if (right < data.size() && data[right] < data[smallest]) {
                smallest = right;
            }
            if (smallest == index) {
                break;
            }
            swap(data[index], data[smallest]);
            index = smallest;
        }
        return result;
    }
};

template<typename T>
class MaxHeap {
private:
    vector<T> data;

public:
    void push(T val) {
        data.push_back(val);
        int index = data.size() - 1;
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (data[parent] >= data[index]) {
                break;
            }
            swap(data[parent], data[index]);
            index = parent;
        }
    }

    T pop() {
        if (data.empty()) {
            throw runtime_error("Heap is empty");
        }
        T result = data[0];
        int index = 0;
        data[index] = data.back();
        data.pop_back();
        while (true) {
            int left = 2 * index + 1;
            int right = 2 * index + 2;
            int largest = index;
            if (left < data.size() && data[left] > data[largest]) {
                largest = left;
            }
            if (right < data.size() && data[right] > data[largest]) {
                largest = right;
            }
            if (largest == index) {
                break;
            }
            swap(data[index], data[largest]);
            index = largest;
        }
        return result;
    }
};

int main() {
    MinHeap<int> minHeap;
    MaxHeap<int> maxHeap;

    // Test MinHeap
    minHeap.push(3);
    minHeap.push(2);
    minHeap.push(15);
    cout << "MinHeap pop: " << minHeap.pop() << endl; // Should print 2

    // Test MaxHeap
    maxHeap.push(3);
    maxHeap.push(2);
    maxHeap.push(15);
    cout << "MaxHeap pop: " << maxHeap.pop() << endl; // Should print 15

    return 0;
}