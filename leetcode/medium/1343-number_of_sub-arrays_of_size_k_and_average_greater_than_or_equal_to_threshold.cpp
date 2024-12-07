class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int running_sum = 0;
        int count = 0;
        int t = k * threshold;

        for (int i = 0; i < arr.size(); i++) {
            running_sum += arr[i];
            if (i >= k) running_sum -= arr[i - k];
            if (i >= k - 1 && running_sum >= t) count++;
        }

        return count;
        
    }
};

/* first solution - passed (but very slow)
class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int x = 0;
        int t = k * threshold;

        for (int i = 0; i < arr.size() - (k-1); i++) {
            int sum = 0;
            for (int j = 0; j < k; j++) {
                sum += arr[i + j];
                if (sum > t) break;
            }
            if (sum >= t) {
                x++;
            }
        }

        return x;
        
    }
};*/
