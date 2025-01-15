class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<vector<int>> ancestors(n);

        for (vector<int>& edge : edges) {
            int from = edge[0];
            int to = edge[1];
            adj[from].push_back(to);
        }

        for (int i = 0; i < n; i++) {
            dfs(i, adj, i, ancestors);
        }

        return ancestors;
    }

    void dfs(int root, vector<vector<int>>& adj, int curr, vector<vector<int>>& ancestors) {
        for (int child : adj[curr]) {
            if (ancestors[child].empty() == false && ancestors[child].back() == root) continue;
            ancestors[child].push_back(root);
            dfs(root, adj, child, ancestors);
        }
    }
};
