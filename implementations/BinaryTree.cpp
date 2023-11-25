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
    BinaryTree() {
		this->root = nullptr;
	}
    void insert(int value) {
		root = insert(root, value);
	}
    void print() {
        this->in_order(this->root);
        cout << endl;
    }

   private:
    Node *root;
	
    Node *insert(Node *root, int value) {
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
    void in_order(Node *node) {
        if (!node)
            return;
        in_order(node->left);
        cout << node->value;
        in_order(node->right);
    }
};


int main() {
    BinaryTree *tree = new BinaryTree();
    tree->insert(2);
    tree->insert(1);
    tree->insert(3);
    tree->print();
    // expected output: 123
}
