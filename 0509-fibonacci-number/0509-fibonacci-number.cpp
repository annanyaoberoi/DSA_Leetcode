class Solution {
public:
    int fib(int n) {
        int ans;
        if (n == 0 || n == 1)
            return n;
        if (n >= 2) {
            ans = fib(n - 1) + fib(n - 2);
        }
        return ans;
    }
};