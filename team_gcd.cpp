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
#include <numeric>
#include <tuple>
#define ll long long

using namespace std;

class Team {
public:
    vector<int> members;

    Team(int i) {
        members.push_back(i);
    }

    void print() {
        for (int i : members) {
            cout << i << ", ";
        }
        cout << endl;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> powers(n);
    vector<Team*> teams(n);

    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;
        powers[i] = p;
        teams[i] = new Team(i);
    }   

    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int t1;
        int t2;
        cin >> t1;
        cin >> t2;

        // merge t2 and t1, pick lowest index as base
        if (t1 > t2) {
            teams[t2]->members.push_back(t1);
            teams[t1] = teams[t2];
        } else {
            teams[t1]->members.push_back(t2);
            teams[t2] = teams[t1];
        }

        // output the power 
        int curr = powers[t1 - 1];
        vector<int> members = teams[t1]->members;

        int x = members.size();
        for (int j = 0; j < x; j++) {
            curr = __gcd(curr, powers[members[j] - 1]);
        }

        cout << curr << endl;
    }
}
