class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq;

        for (int i : gifts) {
            pq.push(i);
        }

        for (int i = 0; i < k; i++) {
            int t = pq.top();
            pq.pop();
            pq.push(floor(sqrt(t)));
        }

        // sum remaining
        long long sum = 0;
        while (!pq.empty()) {
            sum += pq.top();
            pq.pop();
        }

        return sum;
    }
};
