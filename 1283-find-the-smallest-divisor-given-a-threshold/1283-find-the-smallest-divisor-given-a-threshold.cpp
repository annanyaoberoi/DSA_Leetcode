class Solution {
public:
    int sumofdiv(vector<int>& nums, int div) {
        int sum = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            sum += ceil((double)(nums[i]) / (double)(div));
        }return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int maxi = INT_MIN;
        for (int i = 0; i< nums.size(); i++){
            maxi = max(maxi, nums[i]);
        }
        int low = 1;
        int high = maxi;
        int ans = -1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (sumofdiv(nums, mid) <= threshold) {
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }return ans;
    }
};