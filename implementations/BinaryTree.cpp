#include <iostream>
#include <string>
#include <vector>

using namespace std;

// binary tree implementation & basic test

class Node {
public:
  Node *left;
  Node *right;
  int value;

  Node(int value);
};

Node::Node(int value) {
  this->value = value;
  this->left = nullptr;
  this->right = nullptr;
}

class BinaryTree {
public:
  Node *root;
  BinaryTree();
  void insert(int value);
  void print();

private:
  Node *insert(Node *root, int value); // recursive function to help insertion
  void in_order(Node* node);
};

BinaryTree::BinaryTree() { this->root = nullptr; }
void BinaryTree::insert(int value) { root = insert(root, value); }
Node* BinaryTree::insert(Node *root, int value) {
  if (!root) {
    return new Node(value);
  }

  // we ignore same-value scenarios.
  if (value < root->value) {
    root->left = insert(root->left, value);
  } else if (value > root->value) {
    root->right = insert(root->right, value);
  }
  return root;
}

void BinaryTree::print() {
  this->in_order(this->root);
  cout << endl;
}

void BinaryTree::in_order(Node* node) {
  if (!node) return;
  in_order(node->left);
  cout << node->value;
  in_order(node->right);
}

int main() {
  BinaryTree* tree = new BinaryTree();
  tree->insert(2);
  tree->insert(1);
  tree->insert(3);
  tree->print();
  // expected output: 123
}
