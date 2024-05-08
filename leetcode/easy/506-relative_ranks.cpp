class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<int> sorted;
        for (int i : score) {
            sorted.push_back(i);
        }
        sort(sorted.begin(), sorted.end());
        reverse(sorted.begin(), sorted.end());

        vector<string> results;
        for (int i : score) {
            int pos = find(sorted.begin(), sorted.end(), i) - sorted.begin();
            //cout << "pos of " << i << ": " << pos << endl;
            if (pos == 0) {
                results.push_back("Gold Medal");
            } else if (pos == 1) {
                results.push_back("Silver Medal");
            } else if (pos == 2) {
                results.push_back("Bronze Medal");
            } else {
                results.push_back(to_string(pos + 1));
            }
        }
        return results;
    }
};
