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
    BinaryTree() {
        this->root = nullptr;
    }
    void insert(int value) {
        root = insert(root, value);
    }
	// runtime: O(log n)
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
	// runtime: O(log n)
    Node *search(int value) {
        Node *curr = root;
        while (curr) {
            if (curr->value == value) {
                return curr;
            }
            if (value < curr->value) {
                curr = curr->left;
            } else {
                curr = curr->right;
            }
        }
        return nullptr;
    }
    // find min
	// runtime: O(log n)
	Node* minimum(Node* node) {
		Node* curr = node;
		while (curr->left) {
			curr = curr->left;
		}
		return curr;
	}
    // find max
	// runtime: O(log n)
	Node* maximum() {
		Node* curr = root;
		while (curr->right) {
			curr = curr->right;
		}
		return curr;
	}

	void remove(int value) {
		root = remove(root, value);
	}
	// runtime: O(log n)
	Node* remove(Node* node, int value) {
		if (!node) {
			return nullptr;
		}
		if (value < node->value) {
			node->left = remove(node->left, value);
		} else if (value > node->value) {
			node->right = remove(node->right, value);
		} else {
			// we found the node to delete
			if (!node->left && !node->right) {
				// no children
				delete node;
				return nullptr;
			} else if (!node->left) {
				// one child
				Node* temp = node->right;
				delete node;
				return temp;
			} else if (!node->right) {
				// one child
				Node* temp = node->left;
				delete node;
				return temp;
			} else {
				// two children
				Node* temp = minimum(node->right);
				node->value = temp->value;
				node->right = remove(node->right, temp->value);
			}
		}
		return node;
	}
    // delete
    void print() {
        this->in_order(this->root);
        cout << endl;
    }
    
    void in_order(Node *node) {
        if (!node)
            return;
        in_order(node->left);
        cout << node->value << ", ";
        in_order(node->right);
    }
};

int main() {
    // Create a binary tree
    BinaryTree binaryTree;

    // Insert some values
    binaryTree.insert(50);
    binaryTree.insert(30);
    binaryTree.insert(70);
    binaryTree.insert(20);
    binaryTree.insert(40);
    binaryTree.insert(60);
    binaryTree.insert(80);

    // Print the tree (in-order traversal)
    cout << "In-order traversal: ";
    binaryTree.print(); // Output: 20 30 40 50 60 70 80

    // Search for a value
    int searchValue = 40;
    Node *searchResult = binaryTree.search(searchValue);
    if (searchResult) {
        cout << "Value " << searchValue << " found in the tree." << endl;
    } else {
        cout << "Value " << searchValue << " not found in the tree." << endl;
    }

    // Find minimum and maximum values
    Node *minNode = binaryTree.minimum(binaryTree.root);
    Node *maxNode = binaryTree.maximum();
    cout << "Minimum value: " << minNode->value << endl; // Output: 20
    cout << "Maximum value: " << maxNode->value << endl; // Output: 80

    // Remove a value
    int removeValue = 30;
    binaryTree.remove(removeValue);
    cout << "After removing " << removeValue << ": ";
    binaryTree.print(); // Output: 20 40 50 60 70 80

    // Test removing a non-existent value
    int nonExistentValue = 55;
    binaryTree.remove(nonExistentValue);
    cout << "After removing non-existent value " << nonExistentValue << ": ";
    binaryTree.print(); // Output: 20 40 50 60 70 80

    // Test removing the root
    int rootValue = 50;
    binaryTree.remove(rootValue);
    cout << "After removing root " << rootValue << ": ";
    binaryTree.print(); // Output: 20 40 60 70 80

    return 0;
}
