#include <iostream>
struct node {
  int data;
  node *next;
};

void reverseRecustPrint(node *head) {
  if (head == nullptr)
    return;

  reverseRecustPrint(head->next);

  std::cout << head->data << " ";
}
