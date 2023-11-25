#include <iostream>
#include <list>
#include <map>

using namespace std;

class Graph {
   private:
    map<int, list<int>> adj;

   public:
    void add(int vertex) {
        adj[vertex] = list<int>();
    }

    void connect(int vertex1, int vertex2) {
        adj[vertex1].push_back(vertex2);
        adj[vertex2].push_back(vertex1);
    }

    void remove_connection(int vertex1, int vertex2) {
        adj[vertex1].remove(vertex2);
        adj[vertex2].remove(vertex1);
    }

    void remove(int vertex) {
        adj.erase(vertex);
        for (auto& pair : adj) {
            pair.second.remove(vertex);
        }
    }

    void print() {
        for (const auto& pair : adj) {
            cout << "Vertex " << pair.first << " is connected to: ";
            for (const auto& neighbor : pair.second) {
                cout << neighbor << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
};

int main() {
    Graph graph;

    graph.add(1);
    graph.add(2);
    graph.add(3);

    graph.connect(1, 2);
    graph.connect(1, 3);
    graph.connect(2, 3);

    graph.print();  // expected: 1: { 2, 3 }, 2: { 1, 3 }, 3: { 1, 2 }

    graph.remove_connection(1, 2);

    graph.print();  // expected: 1: { 3 }, 2: { 3 }, 3: { 1, 2 }

    graph.remove(1);

    graph.print();  // expected: 2: { 3 }, 3: { 2 }

    return 0;
}
