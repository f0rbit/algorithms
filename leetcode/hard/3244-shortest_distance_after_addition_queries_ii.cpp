class Solution {
public:
    // using a set
    void remove_between(set<int>& s, int l, int r) {
        auto it_start = s.lower_bound(l);
        auto it_end = s.upper_bound(r);
        s.erase(it_start, it_end);
    }

    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        set<int> s;
        for (int i = 0; i < n - 1; i++) {
            s.insert(i);
        }
        vector<int> ans(queries.size());
        for (int i = 0; i < queries.size(); i++) {
            auto q = queries[i];
            remove_between(s, q[0] + 1, q[1] - 1);
            ans[i] = s.size();
        }
        return ans;
    }


    // using a map
    /*vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int> ans(queries.size());
        unordered_map<int, int> map;
        for (int i = 0; i < n - 1; i++) {
            map[i] = i + 1;
        }

        for (int i = 0; i < queries.size(); i++) {
            int u = queries[i][0];
            int v = queries[i][1];

            if (map.find(u) == map.end() || map[u] >= v) {
                ans[i] = map.size();
                continue;
            }

            int j = map[u];
            while (j < v) {
                if (map.find(j) != map.end()) {
                    map.erase(map.find(j));
                }
                j++;
            }
            map[u] = v;

            ans[i] = map.size();
        }
        return ans;
    }*/
};
