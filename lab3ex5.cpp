#include <iostream>
using std::cout, std::endl;

class Account {
private:
  double balance;
  int accountNumber;

  double accountBalance() { return balance; }

  bool validateAccount() { return balance >= 0 && accountNumber > 0; }

  bool checkSecurityRules() { return balance < 1000000; }

public:
  Account(int accNum, double bal) {
    accountNumber = accNum;
    balance = bal;
  }

  friend class Verifier;
};

class Verifier {
public:
  void verifyAccount(Account &acc) {
    if (acc.validateAccount()) {
      cout << "Account is valid" << endl;
    } else {
      cout << "Account is invalid" << endl;
    }
  }

  void auditAccount(Account &acc) {
    cout << "Auditing Account #" << acc.accountNumber << endl;
    cout << "Balance: $" << acc.accountBalance() << endl;
    cout << "Security Rules Check: "
         << (acc.checkSecurityRules() ? "Passed" : "Failed") << endl;
  }

  void generateReport(Account &acc) {
    cout << "\n=== Audit Report ===" << endl;
    cout << "Account Number: " << acc.accountNumber << endl;
    cout << "Current Balance: $" << acc.accountBalance() << endl;
    cout << "Validation Status: "
         << (acc.validateAccount() ? "Valid" : "Invalid") << endl;
    cout << "Security Status: "
         << (acc.checkSecurityRules() ? "Compliant" : "Non-compliant") << endl;
  }
};

int main() {
  Account acc(12345, 50000.00);
  Verifier auditor;

  auditor.verifyAccount(acc);
  auditor.auditAccount(acc);
  auditor.generateReport(acc);

  return 0;
}
