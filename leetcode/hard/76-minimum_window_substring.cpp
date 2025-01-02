class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() == 0 || t.size() == 0) return "";
        unordered_map<char, int> counts;
        for (char c : t) {
            counts[c]++;
        }

        int req = counts.size();
        int left = 0;
        int right = 0;
        int formed = 0;
        unordered_map<char, int> windows;
        int ans[3] = { -1, 0, 0};
        while (right < s.size()) {
            char c = s[right];
            windows[c]++;
            if (counts.find(c) != counts.end() && windows[c] == counts[c]) formed++;

            while (left <= right && formed == req) {
                c = s[left];
                if (ans[0] == -1 || right - left + 1 < ans[0]) {
                    ans[0] = right - left + 1;
                    ans[1] = left;
                    ans[2] = right;
                }
                windows[c]--;
                if (counts.find(c) != counts.end() && windows[c] < counts[c]) formed--;
                left++;
            }
            right++;
        }

        if (ans[0] == -1) return "";
        return s.substr(ans[1], ans[2] - ans[1] + 1);
    }
};
