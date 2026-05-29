#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

long long mergeComps = 0;
long long quickComps = 0;

void merge(std::vector<int>& arr, int l, int m, int r) {
    std::vector<int> L(arr.begin() + l, arr.begin() + m + 1);
    std::vector<int> R(arr.begin() + m + 1, arr.begin() + r + 1);
    int i = 0, j = 0, k = l;
    while (i < (int)L.size() && j < (int)R.size()) {
        mergeComps++;
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
        quickComps++;
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

void runTests(const std::string& label, const std::vector<int>& arr) {
    std::vector<int> mArr = arr;
    std::vector<int> qArr = arr;
    
    mergeComps = 0;
    mergeSort(mArr, 0, mArr.size() - 1);
    
    quickComps = 0;
    quickSort(qArr, 0, qArr.size() - 1);
    
    std::cout << label << ":\tMerge=" << mergeComps << "\tQuick=" << quickComps << std::endl;
}

int main() {
    int n = 15;
    std::vector<int> sorted(n), reversed(n), random = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5, 8, 9, 7, 9};
    std::iota(sorted.begin(), sorted.end(), 1);
    reversed = sorted;
    std::reverse(reversed.begin(), reversed.end());

    runTests("Sorted  ", sorted);
    runTests("Reversed", reversed);
    runTests("Random  ", random);

    return 0;
}
