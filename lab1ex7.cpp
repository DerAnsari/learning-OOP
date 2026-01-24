#include <iostream>
#include <string>

using std::cout, std::endl, std::string, std::to_string;

class Book {
  string bookName{""}, authorName{""}, publisher{""};
  int ISBN{0};

public:
  Book(string b, int i, string a, string p) {
    this->bookName = b;
    this->ISBN = i;
    this->authorName = a;
    this->publisher = p;
  }

  string getBookName() { return this->bookName; }
  int getISBN() { return this->ISBN; }
  string getAuthorName() { return this->authorName; }
  string getPublisher() { return this->publisher; }

  void setBookName(string bookName) { this->bookName = bookName; }
  void setISBN(int ISBN) { this->ISBN = ISBN; }
  void setAuthorName(string authorName) { this->authorName = authorName; }
  void setPublisher(string publisher) { this->publisher = publisher; }

  string getBookInfo() {
    return "Title: " + this->bookName + " | ISBN: " + to_string(this->ISBN) +
           " | Author: " + this->authorName +
           " | Publisher: " + this->publisher;
  }
};

int main() {

  Book library[5] = {
      Book("The Rust Programming Language", 101, "Steve Klabnik",
           "No Starch Press"),
      Book("Clean Code", 102, "Robert C. Martin", "Prentice Hall"),
      Book("Dune", 103, "Frank Herbert", "Chilton Books"),
      Book("The Great Gatsby", 104, "F. Scott Fitzgerald", "Scribner's"),
      Book("Beyond Good and Evil", 105, "Friedrich Nietzsche",
           "C. G. Naumann")};

  cout << "--- Library Book Info ---" << endl;
  for (int i = 0; i < 5; i++) {
    cout << library[i].getBookInfo() << endl;
  }

  cout << "\nUpdating Book 1 title..." << endl;
  library[0].setBookName("The Rust Book (2nd Ed)");
  cout << "New Title: " << library[0].getBookName() << endl;

  return 0;
}
