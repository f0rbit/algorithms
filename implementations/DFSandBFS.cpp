#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <vector>

using namespace std;

// node structure for the graph
class Node {
   public:
    int data;
    vector<Node*> neighbors;

    Node(int value) : data(value) {}

    // insert a neighbor
    void insert_neighbor(Node* neighbor) {
        neighbors.push_back(neighbor);
    }

    // check if a neighbor with given value exists
    bool has_neighbor(int value) {
        for (Node* neighbor : neighbors) {
            if (neighbor->data == value) {
                return true;
            }
        }
        return false;
    }

    // remove a neighbor with given value
    void remove_neighbor(int value) {
        neighbors.erase(remove_if(neighbors.begin(), neighbors.end(), [value](Node* neighbor) { return neighbor->data == value; }), neighbors.end());
    }
};

// graph class
class Graph {
   public:
    Node* root;

    Graph(Node* root) {
        this->root = root;
    }

    // insert a node with given value
    void insert(int value) {
        if (root == nullptr) {
            root = new Node(value);
            return;
        }
        Node* new_node = new Node(value);
        root->insert_neighbor(new_node);
    }

    // find a node with given value using BFS
    Node* bfs_search(int target) {
        queue<Node*> bfs_queue;
        set<Node*> visited;

        bfs_queue.push(root);
        visited.insert(root);

        while (!bfs_queue.empty()) {
            Node* current = bfs_queue.front();
            bfs_queue.pop();

            // check if the current node has the target value
            if (current->data == target) {
                return current;
            }

            // enqueue neighbors if not visited
            for (Node* neighbor : current->neighbors) {
                if (visited.find(neighbor) == visited.end()) {
                    bfs_queue.push(neighbor);
                    visited.insert(neighbor);
                }
            }
        }

        return nullptr;  // target not found
    }

    // find a node with given value using DFS
    Node* dfs_search(int target) {
        set<Node*> visited;
        return dfs_search_recursive(root, target, visited);
    }

    // recursive helper function for DFS search
    Node* dfs_search_recursive(Node* current, int target, set<Node*>& visited) {
        if (current == nullptr) {
            return nullptr;
        }

        // check if the current node has the target value
        if (current->data == target) {
            return current;
        }

        visited.insert(current);

        // recursively search in unvisited neighbors
        for (Node* neighbor : current->neighbors) {
            if (visited.find(neighbor) == visited.end()) {
				Node* result = dfs_search_recursive(neighbor, target, visited);
                if (result != nullptr) {
                    return result;
                }
            }
        }

        return nullptr;  // target not found
    }
};

int main() {
    Node* root = new Node(1);
    root->insert_neighbor(new Node(2));
    root->insert_neighbor(new Node(3));
    root->neighbors[0]->insert_neighbor(new Node(4));
    root->neighbors[0]->insert_neighbor(new Node(5));
    root->neighbors[1]->insert_neighbor(new Node(6));
    root->neighbors[1]->insert_neighbor(new Node(7));
    root->neighbors[1]->neighbors[0]->insert_neighbor(new Node(8));
    Graph graph(root);

    // BFS search
    cout << "BFS Search: " << (graph.bfs_search(4) != nullptr ? "Found" : "Not Found") << endl;

    // DFS search
    cout << "DFS Search: " << (graph.dfs_search(4) != nullptr ? "Found" : "Not Found") << endl;

    return 0;
}
