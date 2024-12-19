class Solution {
public:
    int myAtoi(string s) {
        bool positive = true;
        string number;

        // trim leading whitespace
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') continue;
            number = s.substr(i);
            break;
        }

        if (number[0] == '-') {
            positive = false;
        }
        if (number[0] == '-' || number[0] == '+') {
            number = number.substr(1);
        }

        // skip all leading 0's
        while (number.size() > 0 && number[0] == '0') {
            number = number.substr(1);
        }

        for (int i = 0; i < number.size(); i++) {
            if (!isdigit(number[i])) {
                number = number.substr(0, i);
                break;
            }
        }
        reverse(number.begin(), number.end());
        long long x = 0;
        for (int i = 0; i < number.size(); i++) {
            x += (number[i] - '0') * (pow(10, i));
            cout << x << endl;

            if (x > INT32_MAX || i > 10) return positive ? INT32_MAX : (INT32_MIN);
        }

        return positive ? x : (x * -1);
    }
};