class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if (str1.size() < str2.size()) swap(str1, str2);
        for (int i = str2.size(); i > 0; i--) {
            string div = str2.substr(0, i);
            bool valid = true;
            for (int j = 0; j < str1.size(); j += i) {
                if (str1.substr(j, i) != div) valid = false;
            }
            // check that div also fits in str2
            for (int j = 0; j < str2.size(); j += i) {
                if (str2.substr(j, i) != div) valid = false;
            }
            if (valid) return div;
        }
        return "";
    }
};
