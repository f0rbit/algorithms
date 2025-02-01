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
#include <bits/stdc++.h>
#define ll long long

// I THINK THIS IS AN OFF BY ONE?????

using namespace std;

int main()
{

    int X;
    cin >> X;
    int Y;
    cin >> Y;


    vector<vector<int>> dp(X + 1, vector<int>(Y + 1, 0));

    for (int i = 0; i <= X; i++) { // row
        for (int j = 0; j <= Y; j++) { // column
            if (i == 0 && j == 0) {
                dp[i][j] = 0;
            } else {
                int risk = __builtin_popcount(i ^ j);
                int above = (i > 0) ? max(dp[i-1][j], risk) : INT32_MAX;
                int left = (j > 0) ? max(dp[i][j-1], risk) : INT32_MAX;
                dp[i][j] = min(above, left);
            }
        }
    }

    cout << dp[X][Y] << endl;
}
