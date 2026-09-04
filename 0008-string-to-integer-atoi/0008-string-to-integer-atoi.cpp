class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int n = s.size();
        int sign = 1;
        long long ans = 0;

        // Skip spaces
        while (i < n && s[i] == ' ') {
            i++;
        }

        // Sign
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-') {
                sign = -1;
            }
            i++;
        }

        // Digits
        while (i < n && isdigit(s[i])) {
            int digit = s[i] - '0';

            // Overflow check
            if (ans > INT_MAX / 10 ||
                (ans == INT_MAX / 10 && digit > INT_MAX % 10)) {
                return sign == 1 ? INT_MAX : INT_MIN;
            }

            ans = ans * 10 + digit;
            i++;
        }

        return ans * sign;
    }
};