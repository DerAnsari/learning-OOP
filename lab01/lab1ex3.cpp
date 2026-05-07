#include <iostream>
#include <string>

using std::cout, std::endl, std::cin, std::string;

class Book {
  string title{""};
  int code{0};
  int price{0};
  float rating{0};
  int totalRatings{0};

public:
  Book(string t, int c, int p) {
    title = t;
    code = c;
    price = p;
  };

  void review(float grd) {
    if (totalRatings == 0) {
      rating = grd;
      totalRatings++;
    } else {
      rating = ((rating * totalRatings) + grd) / (totalRatings + 1);
    }
  };

  float getScore() { return rating; };

  int getPrice() { return price; };

  int getCode() { return code; }
};

int main() {
  Book books[5] = {
      Book("The C\texttt{++} Programming Language", 1, 60),
      Book("The Mythical Man-month", 2, 40),
      Book("The Pragmatic Programmer: Your Journey to Mastery", 3, 50),
      Book("The Art of Computer Programming", 4, 50),
      Book("C\texttt{++} For Dummies", 5, 30)};
  books[0].review(5);
  books[0].review(4);
  books[1].review(4);
  books[2].review(2);
  books[3].review(5);
  int code;
  cout << "Enter code: ";
  cin >> code;
  for (int i = 0; i < 5; i++) {
    if (books[i].getCode() == code) {
      if (books[i].getScore() == 0) {
        cout << "The book has not been graded yet" << endl;
      } else {
        cout << "The book has score " << books[i].getScore() << " and price "
             << books[i].getPrice() << endl;
      }
      return 0;
    }
  }
  cout << "The book does not exist" << endl;
  return 0;
}
