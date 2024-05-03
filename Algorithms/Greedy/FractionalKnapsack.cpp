#include <iostream>
#include <vector>
#include <algorithm>

struct Item {
    int weight;
    int value;
};

bool compare(Item a, Item b) {
    double ratioA = (double)a.value / a.weight;
    double ratioB = (double)b.value / b.weight;
    return ratioA > ratioB;
}

double fractionalKnapsack(int capacity, std::vector<Item>& items) {
    std::sort(items.begin(), items.end(), compare);

    double totalValue = 0.0;
    int currentWeight = 0;

    for (const auto& item : items) {
        if (currentWeight + item.weight <= capacity) {
            currentWeight += item.weight;
            totalValue += item.value;
        } else {
            int remainingCapacity = capacity - currentWeight;
            totalValue += (double)item.value / item.weight * remainingCapacity;
            break;
        }
    }

    return totalValue;
}

int main() {
    int capacity = 50;
    std::vector<Item> items = {{10, 60}, {20, 100}, {30, 120}};

    double maxValue = fractionalKnapsack(capacity, items);

    std::cout << "Maximum value that can be obtained: " << maxValue << std::endl;

    return 0;
}