class Solution {
public:
    void combinations(int indx, int target, vector<int> &nums, vector<vector<int>> &ans, vector<int> &ds) {
        if (target == 0) {
            ans.push_back(ds);
            return;
        }
        for (int i = indx; i < nums.size(); i++) {
            if (indx < i && nums[i] == nums[i - 1]) continue;
            if (nums[i] > target) break;
            ds.push_back(nums[i]);
            combinations(i + 1, target - nums[i], nums, ans, ds);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> ds;
        combinations(0, target, nums, ans, ds);
        return ans;
    }
};