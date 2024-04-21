class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if (source == destination) return true;

        vector<vector<int>> connections(n);
        for (int i = 0; i < edges.size(); i++) {
            connections[edges[i][0]].push_back(edges[i][1]);
            connections[edges[i][1]].push_back(edges[i][0]);
        }
        queue<int> q;
        vector<int> visited(n, 0);
        // visit source
        visited[source] = 1;
        q.push(source);

        while (!q.empty()) {
            int v = q.front();
            q.pop();
            if (v == destination) return true;
            for (int x : connections[v]) {
                if (visited[x] == 1) continue;
                visited[x] = 1;
                q.push(x);
            }
        }
        return false;
    }
};
