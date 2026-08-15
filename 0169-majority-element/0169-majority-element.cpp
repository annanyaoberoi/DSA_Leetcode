class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mp;
        for(auto it: nums){
            mp[it]++;
        }
        for (auto ch: mp) {
            if(ch.second > n / 2) {
                return ch.first;
            }
        } return {};
    }
};