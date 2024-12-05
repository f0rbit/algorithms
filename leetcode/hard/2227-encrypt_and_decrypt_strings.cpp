class Encrypter {
public:
    unordered_map<char, string> key_map;
    unordered_map<string, int> dict;

    Encrypter(vector<char>& keys, vector<string>& values, vector<string>& dictionary) {
        for (int i = 0; i < keys.size(); i++) {
            this->key_map[keys[i]] = values[i];
        }
        for (int i = 0; i < dictionary.size(); i++) {
            string k = encrypt(dictionary[i]);
            dict[k]++;
        }
    }
    
    string encrypt(string word1) {
        stringstream r;
        for (int i = 0; i < word1.size(); i++) {
            if (key_map.count(word1[i]) == 0) return "";
            r << key_map[word1[i]];
        }
        return r.str();
    }
    
    int decrypt(string word2) {
        return dict[word2];
    }
};

/* solution 1 @ 00:25:00 - memory limit exceeded (201/211)
class Encrypter {
public:
    unordered_map<char, int> key_map;
    vector<char> keys;
    vector<string> values;
    unordered_map<string, vector<string>> value_map;
    unordered_set<string> dict;
    unordered_map<string, vector<string>> memo;

    Encrypter(vector<char>& keys, vector<string>& values, vector<string>& dictionary) {
        this->keys = keys;
        for (int i = 0; i < keys.size(); i++) {
            this->key_map[this->keys[i]] = i; 
        }
        this->values = values;
        for (int i = 0; i < values.size(); i++) {
            if (this->value_map.count(values[i]) == 0) this->value_map[values[i]] = {};
            string s{keys[i]};
            this->value_map[values[i]].push_back(s);
        }
        for (int i = 0; i < dictionary.size(); i++) {
            dict.insert(dictionary[i]);
        }
    }
    
    string encrypt(string word1) {
        string r = "";
        for (int i = 0; i < word1.size(); i++) {
            if (key_map.count(word1[i]) == 0) return "";
            r += values[key_map[word1[i]]];
        }
        return r;
    }
    
    int decrypt(string word2) {
        vector<string> strings = perms(word2);
        int count = 0;
        for (int i = 0; i < strings.size(); i++) {
            if (dict.contains(strings[i])) count++;
        }
        return count;
    }

    vector<string> perms(string word) {
        if (memo.count(word) != 0) return memo[word];
        if (word.size() < 2) return {};
        if (word.size() == 2) {
            if (value_map.count(word) == 0) {
                memo[word] = {};
                return memo[word];
            } else {
                memo[word] = value_map[word];
                return memo[word];
            }
        }

        vector<string> res;

        vector<string> prefix = perms(word.substr(0, 2));
        vector<string> suffixes = perms(word.substr(2));

        for (string p : prefix) {
            for (string s : suffixes) {
                res.push_back(p + s);
            }
        }

        memo[word] = res;

        return memo[word];
    }
}; */

/**
 * Your Encrypter object will be instantiated and called as such:
 * Encrypter* obj = new Encrypter(keys, values, dictionary);
 * string param_1 = obj->encrypt(word1);
 * int param_2 = obj->decrypt(word2);
 */
