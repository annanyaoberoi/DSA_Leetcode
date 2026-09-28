class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1;
        int prefsum = 0;
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            prefsum += nums[i];
            int remainder = prefsum % k;
            if (remainder < 0) remainder += k;
            if (mp.find(remainder) != mp.end()) cnt += mp[remainder];
            mp[remainder]++;
        }return cnt;
    }
};