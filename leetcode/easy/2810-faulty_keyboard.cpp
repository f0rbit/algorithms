class Solution {
public:
    string finalString(string s) {
        // start at index 1, go to end of string
        for (int i = 1; i < s.size(); i++) { // O(n)
            if (s[i] == 'i') {
                // reverse from 0 to i
                reverse(s.begin(), s.begin() + i); // O(n)
                s.erase(i, 1);
                i--;
            }
        }
        
        return s;
    }
};
