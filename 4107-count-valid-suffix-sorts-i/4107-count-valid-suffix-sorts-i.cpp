class Solution {
public:
    int countSuffix(vector<int>& nums, vector<int>& target) {

        int n = nums.size();

        vector<int> a = nums;
        vector<int> b = target;

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        if(a != b)
            return 0;

        vector<bool> suffixOK(n, true);

        for(int i = n - 2; i >= 0; i--) {
            suffixOK[i] = suffixOK[i + 1] &&
                          (target[i] >= target[i + 1]);
        }

        int ans = 0;
        bool prefixOK = true;

        for(int i = 0; i < n; i++) {

            if(prefixOK && suffixOK[i]) {
                ans++;
            }

            if(nums[i] != target[i]) {
                prefixOK = false;
            }
        }

        return ans;
    }
};