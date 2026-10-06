class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = INT_MIN;
        unordered_set<char> st;
        int l = 0;
        for (int r = 0; r < s.size(); r++){
            while(st.count(s[r])) {
                st.erase(s[l]);
                l++;
            }
            st.insert(s[r]);
            res = max(res, r - l + 1);
        }return res == INT_MIN ? 0 : res;
    }
};