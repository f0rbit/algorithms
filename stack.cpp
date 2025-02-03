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
    long long n;
    cin >> n;

    long long x = 0;
    long long add = 1;
    int loops = 0;
    while (n >= 0) {
        x += add;
        n -= x;
        add++;
        loops++;

    }

    cout << loops - 1 << endl;
}
