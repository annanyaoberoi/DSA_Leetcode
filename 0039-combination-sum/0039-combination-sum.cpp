class Solution {
public:
    void combinations(int indx, int target, vector<int> &nums, vector<vector<int>> &ans, vector<int> &ds) {
        if (indx == nums.size()) {
            if (target == 0) {
                ans.push_back(ds);
            }return;
        }
        if (nums[indx] <= target) {
            ds.push_back(nums[indx]);
            combinations(indx, target - nums[indx], nums, ans, ds);
            ds.pop_back();
        }
        combinations(indx + 1, target, nums, ans, ds);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        combinations(0, target, nums, ans, ds);
        return ans;
    }
};