#include <iostream>
#include <string>
using std::string, std::cout, std::endl;

class UniRecord {
private:
  string studentName;
  int age, studentID;
  char gender;
  int marksProg, marksRest;

  char getGrade(int marks) {
    if (marks >= 85)
      return 'A';
    if (marks >= 70)
      return 'B';
    if (marks >= 60)
      return 'C';
    if (marks >= 50)
      return 'D';
    return 'F';
  }

  double getGradePoints(char grade) {
    if (grade == 'A')
      return 4.0;
    if (grade == 'B')
      return 3.0;
    if (grade == 'C')
      return 2.0;
    if (grade == 'D')
      return 1.0;
    return 0.0;
  }

public:
  UniRecord(string name, int age, char gender, int id, int prog, int rest)
      : studentName(name), age(age), gender(gender), studentID(id),
        marksProg(prog), marksRest(rest) {}

  void displayProfile() {
    cout << "Name: " << studentName << endl;
    cout << "Age: " << age << endl;
    cout << "Student ID: " << studentID << endl;
    cout << "Gender: " << gender << endl;
  }

  void showGrades() {
    cout << "Programming Fundamentals: " << marksProg
         << " - Grade: " << getGrade(marksProg) << endl;
    cout << "Other Courses: " << marksRest
         << " - Grade: " << getGrade(marksRest) << endl;
  }

  double calculateGPA() {
    double gpa = (getGradePoints(getGrade(marksProg)) +
                  getGradePoints(getGrade(marksRest))) /
                 2.0;
    cout << "GPA: " << gpa << endl;
    return gpa;
  }

  void calculateCGPA(double gpa) { cout << "CGPA: " << gpa << endl; }
};

int main() {
  UniRecord student("Ali", 20, 'M', 12345, 85, 75);
  student.displayProfile();
  student.showGrades();
  double gpa = student.calculateGPA();
  student.calculateCGPA(gpa);
  return 0;
}
