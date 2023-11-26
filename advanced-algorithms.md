# trie data structure
- Trie is a tree-like data structure used for efficient retrieval of keys in a dataset where the keys are usually strings. It is commonly used in search engines and IP routers.
- time complexity: O(N), where N is the length of the key.
- space complexity: O(N*M), where N is the number of keys and M is the average length of the keys.

# vector amortised time
- Vector amortized time refers to the average time per operation in a dynamic array (vector) over a sequence of operations. It accounts for the occasional resizing of the vector.
- time complexity: O(1) on average for most operations, though individual operations may take O(n) time in some cases.
- space complexity: O(n) due to the underlying dynamic array structure.

# bit manipulation
- Bit manipulation involves the manipulation of individual bits in a binary representation of data.
- time complexity: O(1) for basic operations like AND, OR, XOR, shift, etc.
- space complexity: O(1).

# singleton design pattern
- The singleton design pattern ensures that a class has only one instance and provides a global point of access to that instance.
- time complexity: O(1) for accessing the singleton instance.
- space complexity: O(1) since there is only one instance of the class.

# factory design pattern
- The factory design pattern provides an interface for creating instances of a class, but allows subclasses to alter the type of instances that will be created.
- time complexity: O(1) for creating objects using the factory.
- space complexity: O(1) since the pattern focuses on creating objects based on a common interface.

# union-find data structure
- Union-find is a data structure that keeps track of a partition of a set into disjoint subsets and allows efficient union and find operations.
- time complexity: O(log n) for both union and find operations in the average case.
- space complexity: O(n) where n is the number of elements.

# quick select algorithm
- QuickSelect is a variation of the QuickSort algorithm that efficiently finds the k-th smallest element in an unordered list.
- time complexity: O(n) on average, O(n^2) in the worst case.
- space complexity: O(log n) due to the recursive nature of the algorithm.

# balanced binary search tree (avl and red-black trees)
- summary: AVL and Red-Black Trees are self-balancing binary search trees that ensure logarithmic height, providing efficient search, insertion, and deletion operations.
- time complexity: O(log n) for search, insert, and delete operations.
- space complexity: O(n) due to the storage of n elements in the tree.

# minimum spanning tree algorithm
- summary: Minimum Spanning Tree algorithms find the subset of edges that connects all vertices in a weighted graph with the minimum possible total edge weight.
- time complexity: O(E log V) for algorithms like Prim's and Kruskal's, where E is the number of edges and V is the number of vertices.
- space complexity: O(V + E) for storing the graph.

# dijkstra’s shortest path algorithm
- summary: Dijkstra's algorithm finds the shortest paths between nodes in a graph with non-negative edge weights.
- time complexity: O((V + E) log V) using a priority queue, where V is the number of vertices and E is the number of edges.
- space complexity: O(V + E) for storing the graph.

# bellman-ford pathfinding algorithm
- summary: Bellman-Ford is an algorithm that finds the shortest paths from a single source vertex to all other vertices in a graph, even with negative edge weights.
- time complexity: O(V * E), where V is the number of vertices and E is the number of edges.
- space complexity: O(V + E) for storing the graph.