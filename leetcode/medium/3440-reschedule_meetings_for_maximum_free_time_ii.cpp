class Solution {
public:
    int maxFreeTime(int n, vector<int>& start, vector<int>& end) {
        vector<int> gap;
        gap.push_back(start[0]);
        for (int i = 1; i < start.size(); i++) {
            gap.push_back(start[i] - end[i - 1]);
        }
        gap.push_back(n - end.back());
        int m = gap.size();
        vector<int> right(m, 0);
        for (int i = m - 2; i >= 0; i--) {
            right[i] = max(right[i+1], gap[i+1]);
        }

        int ans = 0;
        int left = 0;
        for (int i = 1; i < m; i++) {
            int current = end[i-1] - start[i-1];
            if (current <= max(left, right[i])) {
                ans = max(ans, gap[i-1] + gap[i] + current);
            }
            ans = max(ans, gap[i-1] + gap[i]);
            left = max(left, gap[i-1]);
        }
        return ans;
    }
    // TLE - 689/695
    // int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
    //     int current_max = 0;
    //     for (int x = 0; x < startTime.size(); x++) {
    //         int biggest = freeSlots(eventTime, startTime, endTime, x);
    //         current_max = max(biggest, current_max);
    //     }
    //     return current_max;
    // }

    // int freeSlots(int n, vector<int>& start, vector<int>& end, int remove) {
    //     int last_end = 0;
    //     int duration = end[remove] - start[remove];
    //     // we have to place the removed element back in (reschedule)
    //     // pick the smallest number that is >= than the duration of the removed element
    //     int target_idx = -1;
    //     int target_value = INT32_MAX;

    //     vector<int> free;
    //     for (int i = 0; i < start.size(); i++) {
    //         if (i == remove) continue;
    //         if (start[i] >= last_end) {
    //             int time = start[i] - last_end;
    //             free.push_back(time);
    //             if (time >= duration && time < target_value) {
    //                 target_idx = free.size() - 1;
    //                 target_value = time;
    //             }
    //         }
    //         last_end = end[i];
    //     }
    //     // handle last case
    //     if (last_end < n) {
    //         int time = n - last_end;
    //         free.push_back(time);
    //         if (time >= duration && time < target_value) {
    //             target_idx = free.size() - 1;
    //             target_value = time;
    //         }
    //     }
        
    //     if (target_idx == -1) return -1;
    //     free[target_idx] -= duration;
    //     return *max_element(free.begin(), free.end());
    // }
};
