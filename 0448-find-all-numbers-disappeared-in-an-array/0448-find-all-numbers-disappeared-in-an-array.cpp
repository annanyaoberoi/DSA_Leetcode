class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        set<int> st;
        for (int i = 1; i <= n; i++) {
            st.insert(i);
        }
        for (int i = 0; i < n; i++) {
            if (st.find(nums[i]) != st.end()) st.erase(nums[i]);
        }
        vector<int> ans (st.begin(), st.end());
        return ans;
    }
};