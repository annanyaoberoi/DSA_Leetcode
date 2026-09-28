class Solution {
public:
    void solve(int indx, vector<int> &nums, int target, vector<vector<int>> &ans, vector<int> &ds) {
        if (indx == nums.size()) {
            if (target == 0) {
                ans.push_back(ds);
            }return;
        }
        if (nums[indx] <= target) {
            ds.push_back(nums[indx]);
            solve(indx, nums, target - nums[indx], ans, ds);
            ds.pop_back();   
        }solve(indx + 1, nums, target, ans, ds);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        solve(0, nums, target, ans, ds);
        return ans;
    }
};