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



using namespace std;

int main()
{
    int n;
    cin >> n;
    unordered_map<string, int> count;
    int current_max = -1;
    string max_name = "";

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        count[s]++;

        if (count[s] > current_max) {
            current_max = count[s];
            max_name = s;
        } else if (count[s] == current_max) {
            max_name = s.size() > max_name.size() ? max_name : s;
        }
    }

    cout << max_name << endl;
}
