class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> window (26, 0);
        vector<int> need(26, 0);
        for (char c: p) need[c - 'a']++;
        vector<int> res;
        int l = 0;
        for (int r = 0; r < s.size(); r++) {
            window[s[r] - 'a']++;
            if (r - l + 1 > p.size()) {
                window[s[l] - 'a']--;
                l++;
            } 
            if (window == need) res.push_back(l);
        }return res;
    }
};