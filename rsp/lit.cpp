#include <array>
#include <bitset>
#include <deque>
#include <forward_list>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <random>
#include <utility>
#include <tuple>
#define ll long long

using namespace std;

class Node {
public:
    char c;
    int count;
    vector<Node*> children;

    Node(char c) {
        this->count = 0;
        this->c = c;
        this->children.resize(26);
    }
};

class Trie {
public:
    Node* root;

    Trie() {
        this->root = new Node('0');
    }

    int insert(string s) {
        int sum_power = 0;
        Node* current = root;
        for (char c : s) {
            int index = c - 'A';
            if (current->children[index] != nullptr) {
                sum_power += current->children[index]->count;
                current = current->children[index];
            } else {
                current->children[index] = new Node(c);
                current = current->children[index];
            }
            current->count += 1;
        }

        return sum_power;
    }

};

int main()
{
    Trie* t = new Trie();

    int n;
    cin >> n;

    int power = 0;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        power += t->insert(s);
    }

    cout << power << endl;
}
