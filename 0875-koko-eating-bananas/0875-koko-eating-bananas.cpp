class Solution {
public:
    int maximum(vector<int> &piles) {
        int maxi = INT_MIN;
        for (int i = 0; i < piles.size(); i++) {
            maxi = max(maxi, piles[i]);
        }return maxi;
    }
    long long totaltime(vector<int> &piles, int speed) {
        long long totalhr = 0;
        for (int i = 0; i < piles.size(); i++) {
            totalhr += ceil((double) piles[i]/ (double) speed);
        }return totalhr;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = maximum(piles);
        int ans  =INT_MAX;
        while (low <= high) {
            int mid = (low + high) / 2;
            long long totalhr = totaltime(piles, mid);
            if (totalhr <= h) {
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }return ans;
    }
};