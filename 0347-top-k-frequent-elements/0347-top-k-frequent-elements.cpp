class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> res;
        unordered_map<int, int> mp;
        for (auto i : nums) {
            mp[i]++;
        }
        priority_queue<pair<int, int>> pq;
        for (auto it : mp) {
            pq.push({it.second, it.first});
        }
        while (k--) {
            res.push_back(pq.top().second);
            pq.pop();
        }return res;
    } 
};