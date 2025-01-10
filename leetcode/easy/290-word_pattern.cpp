class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> map_char;
        unordered_map<string, char> map_word;
        
        int index = 0; // count which character in pattern we're at

        // go through each word
        while (s.size() > 0 && index < pattern.size()) {
            // find the next word
            int next_space = s.find(' ');
            string w = next_space == string::npos ? s : s.substr(0, next_space);
            // cut off this word from s
            s = next_space == string::npos ? "" : s.substr(next_space + 1);

            // get the character in pattern
            char c = pattern[index++];

            if (map_char.find(c) == map_char.end()) {
                if (map_word.find(w) != map_word.end()) {
                    return false;
                } else {
                    map_char[c] = w;
                    map_word[w] = c;
                }
            } else {
                string mapped_word = map_char[c];
                if (mapped_word != w) return false;
            }
        }

        // check to see if we have mismatched sizes
        if (index < pattern.size()) return false;
        if (s.size() > 0) return false;

        return true;
    }
};
