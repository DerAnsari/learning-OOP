#include <iostream>
#include <string>

using std::string, std::cout, std::cin, std::endl;

class Student {
private:
  int Scores[5];

public:
  void input() {
    for (int i{0}; i < 5; i++)
      cin >> Scores[i];
  }

  int calculateTotalScore() {
    int sum{0};
    for (int i{0}; i < 5; i++) {
      sum += Scores[i];
    }
    return sum;
  }
};

int main() {
  int numStudents;

  cout << "=== Ali's Merit Position Calculator ===" << endl;
  cout << "Enter the number of students in the class: ";
  cin >> numStudents;

  Student *students = new Student[numStudents];
  int aliIndex = -1;

  cout
      << "\nEnter scores for 5 subjects (Math, Physics, Chemistry, CS, English)"
      << endl;
  cout << "--------------------------------------------------------------------"
       << endl;

  for (int i = 0; i < numStudents; i++) {
    cout << "Student " << (i + 1) << " scores: ";
    students[i].input();
  }

  cout << "\nWhich student number is Ali? (1-" << numStudents << "): ";
  cin >> aliIndex;
  aliIndex--;

  int aliTotal = students[aliIndex].calculateTotalScore();
  cout << "\nAli's total score: " << aliTotal << endl;

  int higherCount = 0;

  cout << "\n=== All Students' Total Scores ===" << endl;
  for (int i = 0; i < numStudents; i++) {
    int total = students[i].calculateTotalScore();
    cout << "Student " << (i + 1);

    if (i == aliIndex) {
      cout << " (Ali)";
    }

    cout << ": " << total;

    if (total > aliTotal && i != aliIndex) {
      cout << " ✓ (Higher than Ali)";
      higherCount++;
    }

    cout << endl;
  }

  cout << "\n=== RESULT ===" << endl;
  if (higherCount == 0) {
    cout << " Congratulations! Ali is the VALEDICTORIAN!" << endl;
    cout << "No students scored higher than Ali." << endl;
  } else {
    cout << "Number of students who scored higher than Ali: " << higherCount
         << endl;
    cout << "Ali's position: " << (higherCount + 1) << " out of " << numStudents
         << endl;
  }
  return 0;
}
