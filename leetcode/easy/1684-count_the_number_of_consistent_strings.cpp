class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        vector<bool> chars(26, false);
        for (char c : allowed) {
            chars[c - 'a'] = true;
        }
        int count = 0;

        int m = words.size();
        for (int j = 0; j < m; j++) {
            int n = words[j].size();
            int i = 0;
            while (i < n) {
                if (!chars[words[j][i] - 'a']) break;
                i++;
            }
            if (i == n) count++;            
        }

        return count;
    }
};
