#include <iostream>
#include <vector>

void printArray(const std::vector<int>& arr) {
    for (int x : arr) std::cout << x << " ";
    std::cout << std::endl;
}

int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            std::swap(arr[i], arr[j]);
            std::cout << "Swap " << arr[j] << " and " << arr[i] << ": ";
            printArray(arr);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    std::cout << "Final pivot swap: ";
    printArray(arr);
    return i + 1;
}

void quickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    std::vector<int> data = {8, 3, 7, 1, 5, 2, 4};
    std::cout << "Initial: ";
    printArray(data);
    
    partition(data, 0, data.size() - 1);
    
    return 0;
}
