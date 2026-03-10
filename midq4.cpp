#include <iostream>
#include <string>
#include <vector>

class Publications {
protected:
  std::string title;
  float price;

public:
  Publications(std::string t, float p) : title(t), price(p) {};
  virtual bool isOversize() const { return false; }
};

class Book : public Publications {
private:
  int pageCount;

public:
  Book(std::string t, int pC, float p) : pageCount(pC), Publications(t, p) {};

  bool isOversize() const override { return (pageCount > 800) ? true : false; }

  void getData() {
    std::cout << title << " " << price << " " << pageCount << std::endl;
  }

  void putData(std::string title, float price, int pageCount) {
    this->title = title;
    this->price = price;
    this->pageCount = pageCount;
  }
};

class Tape : public Publications {
private:
  float playingTime;

public:
  Tape(std::string t, float pT, float p)
      : playingTime(pT), Publications(t, p) {};

  bool isOversize() const override { return (playingTime > 90) ? true : false; }

  void getData() {
    std::cout << title << " " << price << " " << playingTime << std::endl;
  }

  void putData(std::string title, float price, float playingTime) {
    this->title = title;
    this->price = price;
    this->playingTime = playingTime;
  }
};

int main() {
  std::vector<Publications *> pubArr;
  char choice;

  std::cout << "Enter (b) for Book, (t) for Tape, or (q) to quit: ";
  std::cin >> choice;

  if (choice == 'b') {
    std::string title;
    float price;
    int pages;

    std::cout << "Enter Book title, price, and page count: ";
    std::cin >> title >> price >> pages;

    // 2. Dynamically create a Book and store it as a Publication*
    pubArr.push_back(new Book(title, price, pages));

  } else if (choice == 't') {
    std::string title;
    float price;
    float time;

    std::cout << "Enter Tape title, price, and playing time: ";
    std::cin >> title >> price >> time;

    // 3. Dynamically create a Tape and store it as a Publication*
    pubArr.push_back(new Tape(title, price, time));
  }
  return 0;
}
