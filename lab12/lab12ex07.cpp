#include <iostream>
#include <vector>
#include <string>
#include <utility>

template <typename T, typename Compare>
void merge(std::vector<T>& arr, int left, int mid, int right, Compare cmp) {
    std::vector<T> L(arr.begin() + left, arr.begin() + mid + 1);
    std::vector<T> R(arr.begin() + mid + 1, arr.begin() + right + 1);
    int i = 0, j = 0, k = left;
    while (i < (int)L.size() && j < (int)R.size()) {
        if (cmp(L[i], R[j])) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while (i < (int)L.size()) arr[k++] = L[i++];
    while (j < (int)R.size()) arr[k++] = R[j++];
}

template <typename T, typename Compare>
void mergeSort(std::vector<T>& arr, int left, int right, Compare cmp) {
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid, cmp);
    mergeSort(arr, mid + 1, right, cmp);
    merge(arr, left, mid, right, cmp);
}

int main() {
    // (i) vector<int> descending
    std::vector<int> ints = {3, 1, 4, 1, 5, 9, 2};
    mergeSort(ints, 0, ints.size() - 1, [](int a, int b) { return a > b; });
    std::cout << "Ints descending: ";
    for (int x : ints) std::cout << x << " ";
    std::cout << std::endl;

    // (ii) vector<string> by length ascending
    std::vector<std::string> words = {"apple", "pear", "banana", "kiwi"};
    mergeSort(words, 0, words.size() - 1, [](const std::string& a, const std::string& b) {
        return a.length() < b.length();
    });
    std::cout << "Strings by length: ";
    for (const auto& s : words) std::cout << s << " ";
    std::cout << std::endl;

    // (iii) vector<pair<int,string>> by integer key, ties alphabetically
    std::vector<std::pair<int, std::string>> pairs = {{2, "b"}, {1, "c"}, {2, "a"}, {1, "a"}};
    mergeSort(pairs, 0, pairs.size() - 1, [](const auto& a, const auto& b) {
        if (a.first != b.first) return a.first < b.first;
        return a.second < b.second;
    });
    std::cout << "Pairs: ";
    for (const auto& p : pairs) std::cout << "(" << p.first << "," << p.second << ") ";
    std::cout << std::endl;

    return 0;
}
