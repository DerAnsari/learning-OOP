#include <iostream>
#include <string>
using std::cin, std::endl, std::cout, std::string;

class Person {
protected:
  int employeeID;
  string employeeName = "";
  int monthlyIncome = 0;
  int bonusAmmount = 0;

public:
  void getData() {
    cout << "Enter Employee ID: ";
    cin >> employeeID;
    cout << "Enter Name: ";
    cin.ignore(); // Clear buffer
    getline(cin, employeeName);
    cout << "Enter Monthly Income: ";
    cin >> monthlyIncome;
  }

  void displayData() {
    cout << employeeID << employeeName << monthlyIncome << bonusAmmount;
  }
};

class Admin : public Person {
public:
  void bonus() { bonusAmmount = monthlyIncome * 0.05; }
};

class Account : public Person {
public:
  void bonus() { bonusAmmount = monthlyIncome * 0.05; }
};

int main() {
  cout << "Welcome to the Superhero Bonus Calculator!" << endl;

  Admin hero1;
  cout << "\nRegistering Admin Hero:" << endl;
  hero1.getData();
  hero1.bonus();
  hero1.displayData();

  Account hero2;
  cout << "\nRegistering Accounts Hero:" << endl;
  hero2.getData();
  hero2.bonus();
  hero2.displayData();

  return 0;
}
