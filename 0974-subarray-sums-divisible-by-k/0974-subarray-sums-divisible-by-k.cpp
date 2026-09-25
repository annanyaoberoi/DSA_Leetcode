class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1;
        int pref = 0;
        int cnt = 0;
        for(int i = 0; i < nums.size(); i++) {
            pref += nums[i];
            int remain = pref % k;
            if (remain < 0) remain += k;
            if(mp.find(remain) != mp.end()) cnt += mp[remain];
            mp[remain]++;
        }return cnt;
    }
};