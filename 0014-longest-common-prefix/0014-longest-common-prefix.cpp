class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        int n = strs[0].size();
        for (int i = 0; i < n; i++) {
            for (auto st: strs) {
                if (st[i] != strs[0][i]) return ans;
            } ans += strs[0][i];
        }return ans;
    }
};