const int mod = 1000000007;
class Solution {
    vector<int> subtreeCount; // Stores number of elements in subtree rooted at any node
    vector<int> dp; // Stores answer for subtree rooted at any node
    
    struct BinomialCoefficients{
        vector<int> fact, inverse;

        BinomialCoefficients(int n){
            fact = vector<int>(n+1, 1);
            inverse = vector<int>(n+1, 1);
            for(int i = 2 ; i <= n ; i++){
                fact[i] = 1LL * fact[i-1] * i % mod;
                inverse[i] = getPower(fact[i], mod-2);
            }
        }

        int getPower(int x, int y){
            int res = 1;
            while(y){
                if(y & 1) res = 1LL * res * x % mod;
                y >>= 1;
                x = 1LL * x * x % mod;
            }
            return res;
        }
        
        inline int getNcr(int n, int r){
            return (n >= r ? 1LL * fact[n] * inverse[r] % mod * inverse[n-r] % mod : 0); 
        }
    };
    
    BinomialCoefficients *binomial = NULL;
public:
    int waysToBuildRooms(vector<int>& prevRoom) {
        int n = prevRoom.size();
        subtreeCount = vector<int>(n, 0);
        dp = vector<int>(n, 1);
        binomial = new BinomialCoefficients(n);
        
        // Create and build tree
        vector<int> g[n];
        for(int i = 1 ; i < n ; i++) g[prevRoom[i]].emplace_back(i);
        
        dfs(g, 0);
        return dp[0];
    }
    
    void dfs(vector<int> g[], int node){
        for(int i : g[node]){
            dfs(g, i);
            dp[node] = 1LL * dp[node] * dp[i] % mod;
            subtreeCount[node] += subtreeCount[i];
        }
        
        // Combinatorics part
        int remainingNodes = subtreeCount[node];
        for(int i : g[node]){
            dp[node] = 1LL * dp[node] * binomial->getNcr(remainingNodes, subtreeCount[i]) % mod;
            remainingNodes -= subtreeCount[i];
        }
        
        subtreeCount[node]++; // Including current node in this subtree
    }
};


/* first solution - TLE
i even tried using a bitmask here instead of vector<bool>, but i > 64

class Solution {
public:
    map<vector<bool>, long long> memo;

    int waysToBuildRooms(vector<int>& prevRoom) {
        memo.clear();
        vector<bool> built(prevRoom.size(), false);
        built[0] = true;
        return helper(built, prevRoom) % (1000000007);
    }

    int helper(vector<bool>& built, vector<int>& previous) {
        if (memo.find(built) != memo.end()) return memo[built];

        long long ways = 0;
        for (int i = 1; i < previous.size(); i++) {
            if (built[i]) continue;
            if (!built[previous[i]]) continue;

            built[i] = true;
            ways += helper(built, previous);
            built[i] = false;
        }
        if (ways == 0) ways = 1;
        memo[built] = ways;

        return ways;
    }
}; */
