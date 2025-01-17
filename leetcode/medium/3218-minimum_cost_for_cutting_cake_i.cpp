class Solution {
public:
    int minimumCost(int m, int n, vector<int>& h, vector<int>& v) {
        sort(h.begin(), h.end());
        sort(v.begin(), v.end());
        // starting at the end gets us the biggest cuts first.
        int i = h.size() - 1;
        int j = v.size() - 1;
        int row = 1; // count the horizontal splits
        int col = 1; // count the vertical splits
        int res = 0;

        while (i >= 0 && j >= 0) {
            if (h[i] > v[j]) {
                res += h[i] * col;
                row++;
                i--;
            } else {
                res += v[j] * row;
                col++;
                j--;
            }
        }

        // calculate the leftovers
        while (i >= 0) {
            res += h[i] * col;
            row++;
            i--;
        }

        while (j >= 0) {
            res += v[j] * row;
            col++;
            j--;
        }

        return res;
    }
};
