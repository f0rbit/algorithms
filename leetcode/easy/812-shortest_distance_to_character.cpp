class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int n = s.size();
        vector<int> ans(n);
        int prev = INT16_MIN;

        for (int i = 0; i < n; ++i) {
            if (s[i] == c) prev = i;
            ans[i] = i - prev;
        }

        prev = INT16_MAX;
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == c) prev = i;
            ans[i] = min(ans[i], prev - i);
        }

        return ans;
    }
};
