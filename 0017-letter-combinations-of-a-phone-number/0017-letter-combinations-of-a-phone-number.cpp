class Solution {
public:
    void solve(int indx, string mapping[], string digits, vector<string> &ans, string ds) {
        if (indx >= digits.size()) {
            ans.push_back(ds);
            return;
        }
        int nums = digits[indx] - '0';
        string val = mapping[nums];
        for (int i = 0; i < val.size(); i++) {
            ds.push_back(val[i]);
            solve(indx + 1, mapping, digits, ans, ds);
            ds.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        string ds;
        if (digits.size() == 0) return ans;
        string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        solve(0, mapping, digits, ans, ds);
        return ans;
    }
};