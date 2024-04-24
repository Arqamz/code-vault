#include <iostream>
using namespace std;

void cycleSort(int arr[], int n) {
    for (int cycleStart = 0; cycleStart < n - 1; cycleStart++) {
        int item = arr[cycleStart];
        int pos = cycleStart;
        for (int i = cycleStart + 1; i < n; i++) {
            if (arr[i] < item) {
                pos++;
            }
        }
        if (pos == cycleStart) {
            continue;
        }
        while (item == arr[pos]) {
            pos++;
        }
        if (pos != cycleStart) {
            swap(item, arr[pos]);
        }
        while (pos != cycleStart) {
            pos = cycleStart;
            for (int i = cycleStart + 1; i < n; i++) {
                if (arr[i] < item) {
                    pos++;
                }
            }
            while (item == arr[pos]) {
                pos++;
            }
            if (item != arr[pos]) {
                swap(item, arr[pos]);
            }
        }
    }
}

int main() {
    int arr[] = {5, 2, 8, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Before sorting: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    cycleSort(arr, n);

    cout << "\nAfter sorting: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}