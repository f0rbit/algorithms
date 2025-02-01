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
#define SIZE 17001

// PRE-CALCULATE THE ARRAY!!!!

using namespace std;


int main()
{
    const ll MAX_CHEESE_BALLS = 1e15;

    vector<ll> tetra;
    ll sum = 0, triangular = 0, height = 1;
    while (sum <= MAX_CHEESE_BALLS) {
        triangular += height;
        sum += triangular;
        tetra.push_back(sum);
        height++;
    }

    int n;
    cin >> n;

    while (n--) {
        ll x;
        cin >> x;

        auto it = upper_bound(tetra.begin(), tetra.end(), x);
        cout << (it - tetra.begin()) << endl;
    }
}
