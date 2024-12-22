class Solution {
public:
    string freqAlphabets(string s) {
        string res = "";
        for (int i = 0; i < s.size(); i++) {
            if (i + 2 < s.size() && s[i+2] == '#') {
                int val = stoi(s.substr(i, 2)) - 1;
                res += (char) (val + 'a');
                i += 2;
            } else {
                int val = s[i] - '0' - 1;
                res += (char) (val + 'a');
            }
        }
        return res;
    }
};