class Solution {
public:
    string longestPrefix(string s) {
        vector<int> lp (s.size(), 0);
        int index = 0;
        for (int i = 1; i < s.size();) {
            if (s[i] == s[index]) {
                index++;
                lp[i] = index;
                i++;
                continue;
            }
            if (index != 0) {
                index = lp[index - 1];
            } else {
                i++;
            }
        }

        return s.substr(0, lp.back());
    }
};
