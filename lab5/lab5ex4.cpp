#include <iostream>
using std::cout;

class Payment {
public:
  void virtual processPayment() { cout << "Processing a generic payment"; }
};

class CreditCardPayment : public Payment {
public:
  void processPayment() { cout << "Processing payment via credit card"; }
};

class PaypalPayment : public Payment {
public:
  void processPayment() { cout << "Processing payment via Paypal"; }
};

class CryptoPayment : public Payment {
public:
  void processPayment() { cout << "Processing payment via CryptoCurrency"; }
};

int main() {
  Payment generic;
  CreditCardPayment card;
  PaypalPayment peer;
  CryptoPayment crypto;

  generic.processPayment();
  card.processPayment();
  peer.processPayment();
  crypto.processPayment();
  return 0;
}
