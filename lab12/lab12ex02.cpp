#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

long long mergeComps = 0;

void merge(std::vector<int>& arr, int left, int mid, int right) {
    std::vector<int> L(arr.begin() + left, arr.begin() + mid + 1);
    std::vector<int> R(arr.begin() + mid + 1, arr.begin() + right + 1);

    int i = 0, j = 0, k = left;
    while (i < (int)L.size() && j < (int)R.size()) {
        mergeComps++;
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }
    while (i < (int)L.size()) arr[k++] = L[i++];
    while (j < (int)R.size()) arr[k++] = R[j++];
}

void mergeSort(std::vector<int>& arr, int left, int right) {
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

void runTest(const std::string& label, std::vector<int> arr) {
    mergeComps = 0;
    mergeSort(arr, 0, arr.size() - 1);
    std::cout << label << ": " << mergeComps << " comparisons" << std::endl;
}

int main() {
    int n = 16;
    std::vector<int> sorted(n), reversed(n), random(n);
    
    std::iota(sorted.begin(), sorted.end(), 1);
    
    reversed = sorted;
    std::reverse(reversed.begin(), reversed.end());
    
    random = {13, 1, 8, 3, 5, 2, 7, 10, 15, 4, 6, 11, 14, 9, 12, 16};

    runTest("Already sorted", sorted);
    runTest("Reverse sorted", reversed);
    runTest("Random        ", random);

    return 0;
}
