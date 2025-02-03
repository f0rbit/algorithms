class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int ans = 0;
        int sum = 0;
        int even_sum = 0;
        int odd_sum = 0;
        const int MOD = 1e9+7;
        for (int i : arr) {
            sum += i;

            if (sum % 2 != 0) {
                odd_sum++;
                ans += ((1 + even_sum) % MOD);
            } else {
                even_sum++;
                ans = ((ans + odd_sum) % MOD);
            }
        }

        return ans % MOD;
    }
};
