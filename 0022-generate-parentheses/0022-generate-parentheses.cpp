class Solution {
public:
    void solve(int open, int close, int n, vector<string> &ans, string ds) {
        if (ds.size() == n * 2) {
            ans.push_back(ds);
            return;
        }
        if (open < n) {
            ds.push_back('(');
            solve(open + 1, close, n, ans, ds);
            ds.pop_back();
        }
        if (close < open) {
            ds.push_back(')');
            solve(open, close + 1, n, ans, ds);
            ds.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string ds;
        solve(0, 0, n, ans, ds);
        return ans;
    }
};