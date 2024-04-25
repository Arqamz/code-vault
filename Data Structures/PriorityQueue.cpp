#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template<typename T>
class PriorityQueue {
private:
    vector<T> data;

public:
    void push(T value) {
        data.push_back(value);
        push_heap(data.begin(), data.end());
    }

    void pop() {
        pop_heap(data.begin(), data.end());
        data.pop_back();
    }

    T top() {
        return data.front();
    }

    bool empty() {
        return data.empty();
    }
};

int main() {
    PriorityQueue<int> pq;

    pq.push(3);
    pq.push(5);
    pq.push(1);
    pq.push(8);

    while (!pq.empty()) {
        cout << pq.top() << endl;
        pq.pop();
    }

    return 0;
}