#include <iostream>
#include <string>

using std::string, std::cout, std::endl;

class Artifact {
  string name{""}, registrationID{""}, discoverer{""}, origin{""};

public:
  Artifact(string name, string registrationID, string discoverer,
           string origin) {
    this->name = name;
    this->registrationID = registrationID;
    this->discoverer = discoverer;
    this->origin = origin;
  }

  string getName() { return this->name; }

  string getRegID() { return this->registrationID; }

  string getDisc() { return this->discoverer; }

  string getOrigin() { return this->origin; }

  string getArtifactInfo() {
    return ("Name :" + this->name +
            " registration ID: " + this->registrationID +
            " Discription: " + this->discoverer + " Origin: " + this->origin);
  }
};

int main() {
  Artifact vault[5] = {
      Artifact("Dragon Soul Gem", "DS-001", "Ulfric", "Skyrim"),
      Artifact("Golden Idol", "GI-772", "Indy Jones", "Peru"),
      Artifact("Excalibur", "SW-001", "Arthur", "Camelot"),
      Artifact("Ankh of Life", "EG-443", "Nefertiti", "Egypt"),
      Artifact("Jade Dragon", "JD-109", "Wei Shen", "Hong Kong")};

  cout << "--- Fantasy Museum Vault Catalog ---" << endl;

  for (int i = 0; i < 5; i++) {
    cout << "Entry #" << (i + 1) << ":" << endl;
    cout << vault[i].getArtifactInfo() << endl;
    cout << "---------------------------" << endl;
  }

  return 0;
}
