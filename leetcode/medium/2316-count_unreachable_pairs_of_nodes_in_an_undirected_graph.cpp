class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    long long countPairs(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        rank.resize(n);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        for (vector<int> edge : edges) {
            merge(edge[0], edge[1]);
        }

        map<int, int> comp_size;

        for (int i = 0; i < n; i++) {
            int par = find(i);
            if (!comp_size.count(par)) {
                comp_size[par] = 1;
            } else {
                comp_size[par]++;
            }
        }

        long n_path = 0;
        long nodes = n;
        for (auto const& [key, val] : comp_size) {
            n_path += val * (nodes - val);
            nodes -= val;
        }

        return n_path;
    }

    int find(int i) {
        if (parent[i] == i) return i;
        int res = find(parent[i]);
        parent[i] = res;
        return res;
    }

    void merge(int i, int j) {
        int ip = find(i);
        int jp = find(j);
        if (ip == jp) return;

        if (rank[ip] < rank[jp]) {
            parent[ip] = jp;
        } else if (rank[ip] > rank[jp]) {
            parent[jp] = ip;
        } else {
            parent[jp] = ip;
            rank[ip] = rank[ip] + 1;
        }
    }
};
