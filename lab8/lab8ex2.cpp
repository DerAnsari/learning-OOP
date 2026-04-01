#include <iostream>

class Account {
protected:
  double balance;
  double rate;
  int time;

public:
  Account(double b, double r, int t) : balance(b), rate(r), time(t) {}
  virtual double calculateInterest() = 0;
  virtual ~Account() {}
};

class SavingsAccount : public Account {
public:
  SavingsAccount(double b, double r, int t) : Account(b, r, t) {}

  double calculateInterest() override { return balance * rate * (time / 12.0); }
};

class CheckingAccount : public Account {
private:
  double fee;

public:
  CheckingAccount(double b, double r, int t, double f)
      : Account(b, r, t), fee(f) {}

  double calculateInterest() override {
    return (balance - fee) * rate * (time / 12.0);
  }
};

int main() {
  Account *savings = new SavingsAccount(5000.0, 0.03, 6);
  Account *checking = new CheckingAccount(3000.0, 0.015, 6, 10.0);

  std::cout << "Savings Account Interest: $" << savings->calculateInterest()
            << std::endl;
  std::cout << "Checking Account Interest: $" << checking->calculateInterest()
            << std::endl;

  delete savings;
  delete checking;

  return 0;
}
