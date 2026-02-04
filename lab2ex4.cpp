#include <iostream>
#include <string>

using std::cout, std::endl, std::string;

class user {

  int age{0};
  string name{""};
  char *profileBio{nullptr};
  int *sessionID{nullptr};

public:
  user(int a, string n, char p, int s) {
    age = a;
    name = n;
    profileBio = new char(p);
    sessionID = new int(s);
  }

  user(const user &u) {
    if (u.profileBio != nullptr) {
      profileBio = new char(*u.profileBio);
    } else {
      profileBio = nullptr;
    }

    sessionID = u.sessionID;
  }

  void setBio(char val) { *profileBio = val; }

  void setID(int val) { *sessionID = val; }

  char getBio() const { return *profileBio; }
  int getSession() const { return *sessionID; }
  string getName() const { return name; }
};

int main() {
  user ali(22, "Ali", 'A', 101);

  user copyAli(ali);

  cout << "--- Initial State ---" << endl;
  cout << "Ali Bio: " << ali.getBio() << " | Session: " << ali.getSession()
       << endl;
  cout << "Copy Bio: " << copyAli.getBio()
       << " | Session: " << copyAli.getSession() << endl;

  ali.setBio('Z');
  cout << "\n--- After Changing Ali's Bio to 'Z' ---" << endl;
  cout << "Ali Bio: " << ali.getBio() << " (Changed)" << endl;
  cout << "Copy Bio: " << copyAli.getBio()
       << " (Stayed 'A' - Deep Copy Success!)" << endl;

  ali.setID(999);
  cout << "\n--- After Changing Ali's Session to 999 ---" << endl;
  cout << "Ali Session: " << ali.getSession() << endl;
  cout << "Copy Session: " << copyAli.getSession()
       << " (Also 999 - Shallow Copy Success!)" << endl;

  return 0;
}
