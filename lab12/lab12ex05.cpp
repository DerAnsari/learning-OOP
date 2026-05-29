#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <ctime>

long long quickComps = 0;

int partitionLast(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        quickComps++;
        if (arr[j] <= pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSortLast(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partitionLast(arr, low, high);
        quickSortLast(arr, low, pi - 1);
        quickSortLast(arr, pi + 1, high);
    }
}

int partitionRandom(std::vector<int>& arr, int low, int high) {
    int randomIdx = low + std::rand() % (high - low + 1);
    std::swap(arr[randomIdx], arr[high]);
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        quickComps++;
        if (arr[j] <= pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSortRandom(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partitionRandom(arr, low, high);
        quickSortRandom(arr, low, pi - 1);
        quickSortRandom(arr, pi + 1, high);
    }
}

int main() {
    std::srand(std::time(0));
    int n = 15;
    std::vector<int> data(n);
    std::iota(data.begin(), data.end(), 1);

    quickComps = 0;
    std::vector<int> lastData = data;
    quickSortLast(lastData, 0, n - 1);
    std::cout << "Last-element pivot comparisons: " << quickComps << std::endl;
    std::cout << "Theoretical n(n-1)/2: " << (n * (n - 1)) / 2 << std::endl;

    quickComps = 0;
    std::vector<int> randomData = data;
    quickSortRandom(randomData, 0, n - 1);
    std::cout << "Random pivot comparisons: " << quickComps << std::endl;

    return 0;
}
