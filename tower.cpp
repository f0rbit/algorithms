#include <array>
#include <bitset>
#include <deque>
#include <forward_list>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <random>
#include <utility>
#include <tuple>
#define ll long long

using namespace std;

void backtrack(vector<string>& current, vector<string>& remaining,  string prev, int n) {
    for (int i = 0; i < remaining.size(); i++) {
        string s = remaining[i];
        if (s == "") continue;
        // if we can stack s under prev, add to current, remove from remaining & recurse.
        if (prev[0] == s[0] || prev[1] == s[1]) {
            current.push_back(s);
            remaining[i] = "";
            backtrack(current, remaining, s, n);
            remaining[i] = s;
            if (current.size() == n) return;
            current.pop_back();
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<string> strings;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        strings.push_back(s);
    }

    vector<string> result;

    for (int i = 0; i < n; i++) {
        string s = strings[i];
        result.push_back(s);
        strings[i] = "";
        backtrack(result, strings, s, n);
        strings[i] = s;
        if (result.size() == n) break;
        result.clear();
    }

    if (result.size() != n) {
        cout << "-1" << endl;
    } else {
        // result
        for (string s : result) {
            cout << s << endl;
        }
    }
}
