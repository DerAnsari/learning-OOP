#include <iostream>

class BankAccount {
private:
  double balance;

public:
  void setBalance(double balance) { this->balance = balance; }
  double getBalance() { return balance; }
};

class savingsAccount : protected BankAccount {
public:
  savingsAccount(double balance) { setBalance(balance); }
  void addInterest(double rate) {
    double balance = getBalance();
    std::cout << "Previous Balance is: " << getBalance() << "\n";
    setBalance(balance + (balance * (rate / 100)));
    std::cout << "New Balance is: " << getBalance() << "\n";
  }
};

int main() {
  savingsAccount obj(100.0);
  obj.addInterest(8);

  // obj.getBalance();  this wont work because setbalance is a member function
  // of
  //  the base class, and we can only access it in the derived
  //  class
}
