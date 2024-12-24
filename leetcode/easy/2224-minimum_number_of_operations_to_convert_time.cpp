class Solution {
public:
    int convertTime(string current, string correct) {
        int current_time = toMinutes(current);
        int target_time = toMinutes(correct);

        int ops[4] = { 60,15,5,1 };
        
        int ans = 0;
        int diff = target_time - current_time;
        for (int op : ops) {
            ans += diff / op;
            diff %= op;
        }
        return ans;
    }

    int toMinutes(string time) {
        int hours = stoi(time.substr(0, 2));
        int minutes = stoi(time.substr(3, 2));

        return hours * 60 + minutes;
    }
};