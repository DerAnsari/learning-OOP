#include <iostream>
#include <vector>
#include <string>

struct Student {
    std::string name;
    double gpa;
    int year;
};

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

template <typename T, typename Compare>
int partition(std::vector<T>& arr, int low, int high, Compare cmp) {
    T pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (cmp(arr[j], pivot)) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

template <typename T, typename Compare>
void quickSort(std::vector<T>& arr, int low, int high, Compare cmp) {
    if (low < high) {
        int pi = partition(arr, low, high, cmp);
        quickSort(arr, low, pi - 1, cmp);
        quickSort(arr, pi + 1, high, cmp);
    }
}

void printStudents(const std::string& label, const std::vector<Student>& students) {
    std::cout << label << ":" << std::endl;
    for (const auto& s : students) {
        std::cout << "  " << s.name << " (GPA: " << s.gpa << ", Year: " << s.year << ")" << std::endl;
    }
}

int main() {
    std::vector<Student> data = {
        {"Alice", 3.8, 2024},
        {"Bob", 3.5, 2023},
        {"Charlie", 3.8, 2023},
        {"David", 3.2, 2024},
        {"Eve", 3.5, 2024}
    };

    auto cmpGPA = [](const Student& a, const Student& b) { return a.gpa > b.gpa; };
    auto cmpYearGPA = [](const Student& a, const Student& b) {
        if (a.year != b.year) return a.year < b.year;
        return a.gpa > b.gpa;
    };
    auto cmpName = [](const Student& a, const Student& b) { return a.name < b.name; };

    std::vector<Student> m1 = data;
    mergeSort(m1, 0, m1.size() - 1, cmpGPA);
    printStudents("Merge Sort (GPA descending)", m1);

    std::vector<Student> m2 = data;
    mergeSort(m2, 0, m2.size() - 1, cmpYearGPA);
    printStudents("Merge Sort (Year ascending, GPA descending)", m2);

    std::vector<Student> q3 = data;
    quickSort(q3, 0, q3.size() - 1, cmpName);
    printStudents("Quick Sort (Name ascending)", q3);

    return 0;
}
