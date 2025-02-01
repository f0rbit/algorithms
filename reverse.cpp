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

int main()
{
    string base;
    cin >> base;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        // perform operations
        string asc(base);
        string desc(base);

        sort(asc.begin(), asc.end());
        sort(desc.begin(), desc.end(), greater<>());

        string absolute = to_string(abs(stoi(desc) - stoi(asc)));

        while (absolute.size() < 4) {
            absolute = "0" + absolute;
        }

        if (base == absolute) {
            break;
        }

        base = absolute;
    }

    cout << base << endl;
}
