#include <iostream>
#include <string>

using std::string, std::cout, std::endl;

class BankAccount {
  string holderName{""};
  int accNumber{0};
  double currBalance{0};

public:
  BankAccount(string holderName, int accNumber, double currBalance) {
    this->holderName = holderName;
    this->accNumber = accNumber;
    this->currBalance = currBalance;
  }

  string getName() { return this->holderName; }

  int getaccNum() { return this->accNumber; }

  void setName(string holderName) { this->holderName = holderName; }

  void setAccNum(int accNumber) { this->accNumber = accNumber; }

  void deposit(double ammount) {
    if (ammount > 0)
      currBalance += ammount;
  }

  void withdraw(double ammount) {
    if (currBalance >= ammount) {
      currBalance -= ammount;
    } else {
      cout << "Insufficient Balance";
    }
  }

  void display() {
    cout << "\n--- Account Statement ---" << endl;
    cout << "Holder: " << this->holderName << endl;
    cout << "Account #: " << this->accNumber << endl;
    cout << "Balance: $" << this->currBalance << endl;
    cout << "-------------------------" << endl;
  }
};

int main() {
  BankAccount myAcc("Ali", 12345, 500.0);

  myAcc.display();
  myAcc.deposit(200.50);
  myAcc.withdraw(1000.0);
  myAcc.withdraw(150.0);

  myAcc.display();

  return 0;
};
