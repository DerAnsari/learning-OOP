#include <cstring>
#include <string>
using std::string;

class User {
  int age;
  string name;
  char *profileBio;
  int *sessionID;

public:
  User(int a, string n, const char *bio, int Id) : age(a), name(n) {
    this->profileBio = new char[std::strlen(bio) + 1];
    std::strcpy(this->profileBio, bio);

    this->sessionID = new int;
    *(this->sessionID) = Id;
  }

  User(User &other) {
    this->age = other.age;
    this->name = other.name;

    this->sessionID = other.sessionID;

    this->profileBio = new char[std::strlen(other.profileBio) + 1];
    std::strcpy(this->profileBio, other.profileBio);
  }
};

int main() { return 0; }
