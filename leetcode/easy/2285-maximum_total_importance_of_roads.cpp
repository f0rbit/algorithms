class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<long long> count(n, 0);

        // use reference here to avoid copying each sub-vector
        for (const auto& road : roads) {
            count[road[0]] += 1;
            count[road[1]] += 1;
        }

        sort(count.begin(), count.end());

        long long sum = 0;
        
        // iterating backwards is slightly more efficient
        for (long long i = count.size() - 1; i >= 0; --i) {
            sum += count[i] * (i+1);
        }

        return sum;
    }
};