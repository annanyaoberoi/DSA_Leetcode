class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1;
        int prefsum = 0;
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            prefsum += nums[i];
            int remove = prefsum - k;
            cnt += mp[remove];
            mp[prefsum]++;
        }return cnt;
    }
};