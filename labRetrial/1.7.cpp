#include <string>
using std::to_string, std::string;

class Book {
  string title, author, publisher;
  int ISBN;

public:
  Book(string t, string a, string p, int i)
      : title(t), author(a), publisher(p), ISBN(i) {}

  string gettitle() { return title; }

  string getAuthor() { return author; }

  string getPublisher() { return publisher; }

  int getisbn() { return ISBN; }

  string getBookInfo() {
    return "Book: " + this->title + "\nAuthor: " + this->author +
           "\nPublisher: " + this->publisher +
           "\nISBN: " + to_string(this->ISBN) + "\n";
  }
};

int main() { return 0; }
