class Solution {
public:
    int val[14][16384], dp[14][16384];

    int dfs(unsigned int mask, int p, vector<int>& nums) {
        if (popcount(mask) == nums.size())
            return abs(p - nums[0]);
        if (dp[p][mask] < 0) {
            dp[p][mask] = INT_MAX;
            for (int n = 1; n < nums.size(); ++n)
                if (((1 << n) & mask) == 0) {
                    int res_n = abs(p - nums[n]) + dfs(mask + (1 << n), n, nums);
                    if (res_n < dp[p][mask]) {
                        dp[p][mask] = res_n;
                        val[p][mask] = n;    
                    }
                }
        }
        return dp[p][mask];
    }

    vector<int> findPermutation(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        dfs(1, 0, nums);
        vector<int> res{0};
        for (uint mask = 1; popcount(mask) < nums.size(); mask += (1 << res.back()))
            res.push_back(val[res.back()][mask]);
        return res;
    }
};

/* second brute force solution
class Solution {
public:
    vector<int> findPermutation(vector<int>& nums) {
        return gen_perms(nums, {}, nums);
    }

    vector<int> smaller_perm(vector<int> a, vector<int> b) {
        if (a.size() != b.size()) return a;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] == b[i]) continue;
            if (a[i] < b[i]) return a;
            if (a[i] > b[i]) return b;
        }
        return a;
    }

    vector<int> gen_perms(vector<int> left, vector<int> current, vector<int> nums) {
        if (left.size() == 0) {
            return current;
        }
        int min = INT32_MAX;
        vector<int> min_perm;
        for (int i = 0; i < left.size(); i++) {
            // take out left[i] and put in current
            vector<int> new_perm(current.begin(), current.end());
            new_perm.push_back(left[i]);
            vector<int> new_left;
            for (int j = 0; j < left.size(); j++) {
                if (i == j) continue;
                new_left.push_back(left[j]);
            }

            vector<int> p = gen_perms(new_left, new_perm, nums);
            int s = score(nums, p);
            if (s < min) {
                min = s;
                min_perm = p;
            } else if (s == min) {
                min_perm = smaller_perm(min_perm, p);
            }
        }

        return min_perm;
    }

    int score(vector<int> nums, vector<int> perm) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += abs(perm[i] - nums[perm[(i + 1) % perm.size()]]);
        }
        return sum;
    }
}; */

/* Initial Brute Force Solution
class Solution {
public:
    vector<int> findPermutation(vector<int>& nums) {
        vector<vector<int>> perms;
        for (auto p : gen_perms(nums, {})) {
            perms.push_back(p);
        }

        int min = INT32_MAX;
        vector<int> min_perm;
        // run through and score all the perms
        for (vector<int> perm : perms) {
            for (int i : perm) {
                cout << i << ", ";
            }
            cout << endl;
            int s = score(nums, perm);
            if (s < min) {
                min = s;
                min_perm = perm;
            } else if (s == min) {
                min_perm = smaller_perm(min_perm, perm);
            }
        }   
        cout << min << endl;

        return min_perm;
    }

    vector<int> smaller_perm(vector<int> a, vector<int> b) {
        if (a.size() != b.size()) return a;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] == b[i]) continue;
            if (a[i] < b[i]) return a;
            if (a[i] > b[i]) return b;
        }
        return a;
    }

    vector<vector<int>> gen_perms(vector<int> left, vector<int> current) {
        vector<vector<int>> res;
        if (left.size() == 0) {
            res.push_back(current);
            return res;
        }
        for (int i = 0; i < left.size(); i++) {
            // take out left[i] and put in current
            vector<int> new_perm(current.begin(), current.end());
            new_perm.push_back(left[i]);
            vector<int> new_left;
            for (int j = 0; j < left.size(); j++) {
                if (i == j) continue;
                new_left.push_back(left[j]);
            }

            for (auto p : gen_perms(new_left, new_perm)) {
                res.push_back(p);
            }
        }

        return res;
    }

    int score(vector<int> nums, vector<int> perm) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += abs(perm[i] - nums[perm[(i + 1) % perm.size()]]);
        }
        return sum;
    }
}; */
