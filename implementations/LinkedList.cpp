#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

// could use templates to make the linked list generic for any
// object type, but for simplicity just using int

/** @todo - make the formatter use 4 spaces instead of 2 */

class Node {
public:
  int value;
  Node *next;

  Node(int value) {
    this->value = value;
    this->next = nullptr;
  }
};

class LinkedList {
public:
  Node *head = nullptr;

  void insert(int value) {
    Node *new_node = new Node(value);
    if (head == nullptr) {
      head = new_node;
      return;
    }
    Node *curr = head;
    while (curr->next) {
      curr = curr->next;
    }
    curr->next = new_node;
  }

  string toString() {
    string res = "";
    // curr node to keep track of position
    Node *curr = head;
    while (curr) {
      res += to_string(curr->value) + ",";
      curr = curr->next;
    }
    // remove trailing comma
    return res.substr(0, res.length() - 1);
  }
};

int main() {
  LinkedList *list = new LinkedList();
  list->insert(1);
  list->insert(2);
  list->insert(3);

  cout << list->toString() << endl;
}
