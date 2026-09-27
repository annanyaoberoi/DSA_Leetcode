class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0;
        int zeros = 0;
        int res = INT_MIN;
        for (int r = 0; r < nums.size(); r++) {
            if(nums[r] == 0) zeros++;
            while (zeros > k) {
                if (nums[l] == 0) zeros--;
                l++;
            }res = max(res, r - l + 1);
        }return res;
    }
};