// modified dfs approach
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> dead_set(deadends.begin(), deadends.end());
        if (dead_set.count("0000")) return -1;

        queue<pair<string, int>> q;
        q.push({ "0000", 0 });
        unordered_set<string> visited;
        visited.insert("0000");

        while (!q.empty()) {
            pair<string, int> curr = q.front();
            q.pop();
            if (curr.first == target) return curr.second;

            for (int i = 0; i < 4; i++) {
                for (int d : { -1, 1 }) {
                    int new_digit = (curr.first[i] - '0' + d + 10) % 10;
                    string new_str = curr.first;
                    new_str[i] = new_digit + '0';

                    if (dead_set.find(new_str) != dead_set.end() || visited.find(new_str) != visited.end()) continue;

                    visited.insert(new_str);
                    q.push({ new_str, curr.second + 1});
                }
            }
        }
        return -1;
    }
};
