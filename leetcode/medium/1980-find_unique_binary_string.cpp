class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums[0].size();
        set<int> containing;

        for (string s : nums) {
            int x = stoi(s, nullptr, 2);
            containing.insert(x);
        }

        cout << (n >> 1) << endl;

        for (int i = n >> 1; i < pow(2,n); i++) {
            if (containing.contains(i)) continue;
            return bitset<32>(i).to_string().substr(32 - n);
        }

        return "";
    }
};
