#include <iostream>
#include <vector>
#include <string>

struct Card {
    int value;
    char suit;
};

void merge(std::vector<Card>& arr, int left, int mid, int right) {
    std::vector<Card> L(arr.begin() + left, arr.begin() + mid + 1);
    std::vector<Card> R(arr.begin() + mid + 1, arr.begin() + right + 1);

    int i = 0, j = 0, k = left;
    while (i < (int)L.size() && j < (int)R.size()) {
        if (L[i].value <= R[j].value) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }
    while (i < (int)L.size()) arr[k++] = L[i++];
    while (j < (int)R.size()) arr[k++] = R[j++];
}

void mergeSort(std::vector<Card>& arr, int left, int right) {
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

int partition(std::vector<Card>& arr, int low, int high) {
    int pivot = arr[high].value;
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j].value <= pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(std::vector<Card>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void printCards(const std::string& label, const std::vector<Card>& cards) {
    std::cout << label << ": ";
    for (const auto& c : cards) std::cout << c.value << c.suit << " ";
    std::cout << std::endl;
}

int main() {
    std::vector<Card> data = {{5, 'H'}, {3, 'C'}, {5, 'S'}, {2, 'D'}, {5, 'D'}};
    
    std::vector<Card> mergeData = data;
    mergeSort(mergeData, 0, mergeData.size() - 1);
    printCards("Merge Sort", mergeData);

    std::vector<Card> quickData = data;
    quickSort(quickData, 0, quickData.size() - 1);
    printCards("Quick Sort", quickData);

    return 0;
}
