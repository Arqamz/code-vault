#include <iostream>
#include <vector>
#include <algorithm>

void countSort(std::vector<int>& arr) {
    int max = *std::max_element(arr.begin(), arr.end());
    int min = *std::min_element(arr.begin(), arr.end());
    int range = max - min + 1;

    std::vector<int> count(range), output(arr.size());

    for (int i = 0; i < arr.size(); i++) {
        count[arr[i] - min]++;
    }

    for (int i = 1; i < count.size(); i++) {
        count[i] += count[i - 1];
    }

    for (int i = arr.size() - 1; i >= 0; i--) {
        output[count[arr[i] - min] - 1] = arr[i];
        count[arr[i] - min]--;
    }

    for (int i = 0; i < arr.size(); i++) {
        arr[i] = output[i];
    }
}

int main() {
    std::vector<int> arr = {4, 2, 2, 8, 3, 3, 1};
    
    std::cout << "Before sorting: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    countSort(arr);

    std::cout << "After sorting: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}