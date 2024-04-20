#include <iostream>
#include <vector>
#include <algorithm>

void bucketSort(std::vector<float>& arr) {
    int n = arr.size();
    std::vector<std::vector<float>> buckets(n);

    // Place elements into buckets
    for (int i = 0; i < n; i++) {
        int bucketIndex = n * arr[i];
        buckets[bucketIndex].push_back(arr[i]);
    }

    // Sort individual buckets
    for (int i = 0; i < n; i++) {
        std::sort(buckets[i].begin(), buckets[i].end());
    }

    // Concatenate sorted buckets
    int index = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < buckets[i].size(); j++) {
            arr[index++] = buckets[i][j];
        }
    }
}

int main() {
    std::vector<float> arr = {0.42, 0.32, 0.33, 0.52, 0.37, 0.47, 0.51};
    
    std::cout << "Before sorting: ";
    for (float num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    bucketSort(arr);

    std::cout << "After sorting: ";
    for (float num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}