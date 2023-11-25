#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

// could use templates to make the linked list generic for any
// object type, but for simplicity just using int

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

	// runtime: O(1)
	// inserts at the beginning of the list
	void insert(int data) {
		Node* node = new Node(data);
		node->next = head;
		head = node;
	}

	// runtime: O(n)
	void remove(int value) {
		if (head == nullptr) {
			return;
		}
		if (head->value == value) {
			head = head->next;
			return;
		}
		Node *curr = head;
		while (curr->next) {
			if (curr->next->value == value) {
				curr->next = curr->next->next;
				return;
			}
			curr = curr->next;
		}
	}

	// runtime: O(n)
	bool contains(int value) {
		Node *curr = head;
		while (curr) {
			if (curr->value == value) {
				return true;
			}
			curr = curr->next;
		}
		return false;
	}

	// runtime: O(n)
	int size() {
		int count = 0;
		Node *curr = head;
		while (curr) {
			count++;
			curr = curr->next;
		}
		return count;
	}

	// runtime: O(n)
	int get(int index) {
		Node *curr = head;
		int count = 0;
		while (curr) {
			if (count == index) {
				return curr->value;
			}
			count++;
			curr = curr->next;
		}
		return -1;
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
    LinkedList list;

    // Test 1: Insert elements
    list.insert(5);
    list.insert(10);
    list.insert(15);
    cout << "Inserted elements: " << list.toString() << endl; // Output: 15,10,5

    // Test 2: Remove element
    list.remove(10);
    cout << "After removing 10: " << list.toString() << endl; // Output: 15,5

    // Test 3: Contains
    cout << "Contains 5? " << (list.contains(5) ? "Yes" : "No") << endl; // Output: Yes
    cout << "Contains 10? " << (list.contains(10) ? "Yes" : "No") << endl; // Output: No

    // Test 4: Size
    cout << "Size of the list: " << list.size() << endl; // Output: 2

    // Test 5: Get element at index
    cout << "Element at index 1: " << list.get(1) << endl; // Output: 5

    return 0;
}
