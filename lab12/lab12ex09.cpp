#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

long long hybridComps = 0;

void insertionSort(std::vector<int>& arr, int low, int high) {
    for (int i = low + 1; i <= high; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= low) {
            hybridComps++;
            if (arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
            } else {
                break;
            }
        }
        arr[j + 1] = key;
    }
}

int medianOfThree(std::vector<int>& arr, int low, int high) {
    int mid = low + (high - low) / 2;
    if (arr[low] > arr[mid]) std::swap(arr[low], arr[mid]);
    if (arr[low] > arr[high]) std::swap(arr[low], arr[high]);
    if (arr[mid] > arr[high]) std::swap(arr[mid], arr[high]);
    return mid;
}

int partition(std::vector<int>& arr, int low, int high) {
    int pivotIdx = medianOfThree(arr, low, high);
    int pivot = arr[pivotIdx];
    std::swap(arr[pivotIdx], arr[high]);
    int i = low - 1;
    for (int j = low; j < high; j++) {
        hybridComps++;
        if (arr[j] <= pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

void hybridSort(std::vector<int>& arr, int low, int high, int k) {
    if (low >= high) return;
    if (high - low + 1 <= k) {
        insertionSort(arr, low, high);
        return;
    }
    int pi = partition(arr, low, high);
    hybridSort(arr, low, pi - 1, k);
    hybridSort(arr, pi + 1, high, k);
}

int main() {
    std::srand(std::time(0));
    std::vector<int> ns = {50, 200, 1000};
    std::vector<int> ks = {5, 10, 20};

    for (int n : ns) {
        std::vector<int> original(n);
        for (int i = 0; i < n; i++) original[i] = std::rand() % 10000;
        
        std::cout << "N = " << n << ":" << std::endl;
        for (int k : ks) {
            std::vector<int> data = original;
            hybridComps = 0;
            hybridSort(data, 0, n - 1, k);
            std::cout << "  Threshold k=" << k << ": " << hybridComps << " comparisons" << std::endl;
        }
    }

    return 0;
}
