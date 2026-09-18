class Solution {
private:
    void recpermute(int indx, vector<int> &nums, vector<vector<int>> &ans) {
        if (indx == nums.size()) {
            ans.push_back(nums);
            return;
        }
        for (int i = indx; i < nums.size(); i++) {
            swap(nums[indx], nums[i]);
            recpermute(indx + 1, nums, ans);
            swap(nums[indx], nums[i]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        recpermute(0, nums, ans);
        return ans;
    }
};