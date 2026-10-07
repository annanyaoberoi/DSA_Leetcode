class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for (int x: nums) {
            mp[x]++;
        }
        vector<pair<int, int>> ans;
        for (auto it: mp) {
            ans.push_back({it.second, it.first});
        }
        sort(ans.rbegin(), ans.rend());
        vector<int> res;
        for (auto it: ans) {
            if (k == 0) break;
            res.push_back(it.second);
            k--;
        }return res;
    }
};