#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <ctime>
#include <iomanip>

void selectionSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx]) minIdx = j;
        }
        std::swap(arr[i], arr[minIdx]);
    }
}

void insertionSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void merge(std::vector<int>& arr, int l, int m, int r) {
    std::vector<int> L(arr.begin() + l, arr.begin() + m + 1);
    std::vector<int> R(arr.begin() + m + 1, arr.begin() + r + 1);
    int i = 0, j = 0, k = l;
    while (i < (int)L.size() && j < (int)R.size()) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while (i < (int)L.size()) arr[k++] = L[i++];
    while (j < (int)R.size()) arr[k++] = R[j++];
}

void mergeSort(std::vector<int>& arr, int l, int r) {
    if (l >= r) return;
    int m = l + (r - l) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
}

int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
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
    std::srand(std::time(0));
    std::vector<int> ns = {100, 1000, 10000};
    
    std::cout << std::left << std::setw(10) << "N" 
              << std::setw(15) << "Selection" 
              << std::setw(15) << "Insertion" 
              << std::setw(15) << "Merge" 
              << std::setw(15) << "Quick" << std::endl;

    for (int n : ns) {
        std::vector<int> original(n);
        for (int i = 0; i < n; i++) original[i] = std::rand() % 100000;

        auto benchmark = [&](auto sortFunc, std::vector<int> data) {
            auto start = std::chrono::high_resolution_clock::now();
            sortFunc(data);
            auto end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double, std::milli> duration = end - start;
            return duration.count();
        };

        double tSelection = benchmark([](auto& d) { selectionSort(d); }, original);
        double tInsertion = benchmark([](auto& d) { insertionSort(d); }, original);
        double tMerge = benchmark([](auto& d) { mergeSort(d, 0, d.size() - 1); }, original);
        double tQuick = benchmark([](auto& d) { quickSort(d, 0, d.size() - 1); }, original);

        std::cout << std::left << std::setw(10) << n 
                  << std::setw(15) << tSelection 
                  << std::setw(15) << tInsertion 
                  << std::setw(15) << tMerge 
                  << std::setw(15) << tQuick << " (ms)" << std::endl;
    }

    return 0;
}
