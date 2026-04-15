#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Student {
  string name;
  double gpa;
  int year;
};

void printStudents(const string &title, const vector<Student> &students) {
  cout << "\n--- " << title << " ---\n";
  cout << "Name\t\tGPA\tYear\n";
  cout << "-------------------------------------\n";
  for (size_t i = 0; i < students.size(); i++) {
    cout << students[i].name << "\t\t" << students[i].gpa << "\t"
         << students[i].year << "\n";
  }
}

bool compareGPADesc(const Student &a, const Student &b) {
  return a.gpa > b.gpa;
}

bool compareYearAscGPADesc(const Student &a, const Student &b) {
  if (a.year != b.year)
    return a.year < b.year;
  return a.gpa > b.gpa;
}

bool compareNameAsc(const Student &a, const Student &b) {
  return a.name < b.name;
}

void selectionSort(vector<Student> &v,
                   bool (*cmp)(const Student &, const Student &)) {
  int n = v.size();
  for (int i = 0; i < n - 1; ++i) {
    int targetIndex = i;
    for (int j = i + 1; j < n; ++j) {
      if (cmp(v[j], v[targetIndex])) {
        targetIndex = j;
      }
    }
    if (targetIndex != i) {
      Student temp = v[i];
      v[i] = v[targetIndex];
      v[targetIndex] = temp;
    }
  }
}

void insertionSort(vector<Student> &v,
                   bool (*cmp)(const Student &, const Student &)) {
  int n = v.size();
  for (int i = 1; i < n; ++i) {
    Student key = v[i];
    int j = i - 1;
    while (j >= 0 && cmp(key, v[j])) {
      v[j + 1] = v[j];
      j--;
    }
    v[j + 1] = key;
  }
}

int main() {
  vector<Student> original = {{"Alice", 3.8, 2023},
                              {"Bob", 3.5, 2024},
                              {"Charlie", 3.8, 2023},
                              {"David", 3.9, 2024},
                              {"Eve", 3.5, 2023}};

  vector<Student> v;

  v = original;
  insertionSort(v, compareGPADesc);
  printStudents("GPA Descending (Insertion)", v);

  v = original;
  insertionSort(v, compareYearAscGPADesc);
  printStudents("Year Asc, GPA Desc (Insertion)", v);

  v = original;
  insertionSort(v, compareNameAsc);
  printStudents("Name Ascending (Insertion)", v);

  return 0;
}
