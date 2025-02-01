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

    vector<bool> possible(101, true);
    possible[0] = false;

    for (int i = 0; i < n; i++) {
        string line;
        cin >> line;

        string yes;
        cin >> yes;

        int number = stoi(line);

        for (int i = 1; i <= 100; i++) {
            if (yes[0] == 'Y') {
                if (i % number != 0) {
                    possible[i] = 0;
                }
            } else {
                if (i % number == 0) {
                    possible[i] = 0;
                }
            }
        }
    }

    // add +1 to end
    for (int i = 1; i <= 100; i++) {
        if (possible[i]) {
            cout << i << endl;
        }
    }
}
