#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using std::cout, std::string, std::vector;

struct Student {
  string name{""};
  double score{0};
};

int main() {
  vector<Student> students{{"Alice", 92}, {"Bob", 78}, {"Charlie", 66},
                           {"Diana", 55}, {"Eve", 48}, {"Frank", 85}};

  vector<string> grades(students.size());

  std::transform(students.begin(), students.end(), grades.begin(),
                 [](const Student &s) {
                   if (s.score >= 80)
                     return "A";
                   if (s.score >= 65)
                     return "B";
                   if (s.score >= 50)
                     return "C";
                   return "F";
                 });

  vector<double> scaledScores(students.size());

  std::transform(students.begin(), students.end(), scaledScores.begin(),
                 [](const Student &s) {
                   if (s.score >= 95)
                     return 100;
                   return static_cast<int>(s.score + 5.0);
                 });

  vector<string> labels(students.size());

  std::transform(students.begin(), students.end(), grades.begin(),
                 labels.begin(), [](const Student &s, const string &grades) {
                   return s.name + " : " + grades;
                 });

  cout << "Final Report:\n";
  for (const auto &label : labels) {
    cout << label << "\n";
  }
};
