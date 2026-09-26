class Solution {
public:
    void solve(string digits, int indx, string ds, vector<string> &ans, string mapping[]) {
        if (indx >= digits.size()) {
            ans.push_back(ds);
            return;
        }
        int nums = digits[indx] - '0';
        string val = mapping[nums];
        for (int i = 0; i < val.size(); i++) {
            ds.push_back(val[i]);
            solve(digits, indx + 1, ds, ans, mapping);
            ds.pop_back();
        }
    } 
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        string ds;
        if (digits.size() == 0) return ans;
        string mapping [10] = {"", "", "abc","def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        int indx = 0;
        solve(digits, 0, ds, ans, mapping);
        return ans;
    }
};