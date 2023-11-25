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
    LinkedList *list = new LinkedList();
    list->insert(1);
    list->insert(2);
    list->insert(3);

    cout << list->toString() << endl;
}
