#include <iostream>
#include <string>

using std::string, std::cout, std::endl;

class Account {
private:
  int account_no{0}, security_code{0};
  double account_bal{0};

public:
  Account(int account_no, int security_code, double account_bal) {
    this->account_no = account_no;
    this->security_code = security_code;
    this->account_bal = account_bal;
  }

  void displayInfo() {
    cout << "Acc No. " << account_no << " Security Code: " << security_code
         << "Account Balance: " << account_bal << endl;
  }
};

int main() {
  Account acc(12345, 1234, 5000.50);
  acc.displayInfo();
  return 0;
}
