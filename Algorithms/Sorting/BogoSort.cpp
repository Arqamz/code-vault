#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

// GOAT Sort, I love gambling w this

// Function to check if the array is sorted
bool isSorted(const std::vector<int>& arr) {
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] < arr[i - 1]) {
            return false;
        }
    }
    return true;
}

// Function to shuffle the array randomly
void shuffleArray(std::vector<int>& arr) {
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(arr.begin(), arr.end(), g);
}

// Bogo Sort implementation
void bogoSort(std::vector<int>& arr) {
    while (!isSorted(arr)) {
        shuffleArray(arr);
    }
}

int main() {
    std::vector<int> arr = {5, 2, 8, 6, 1, 3, 9, 4, 7};
    
    std::cout << "Array before sorting: ";
    for (const auto& num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    
    bogoSort(arr);
    
    std::cout << "Array after sorting: ";
    for (const auto& num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    
    return 0;
}