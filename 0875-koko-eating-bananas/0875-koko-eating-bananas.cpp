class Solution {
public:
    int findmax(vector<int>& v) {
        int maxi = INT_MIN;
        int n = v.size();
        for (int i = 0; i < n; i++) {
            maxi = max(maxi, v[i]);
        }return maxi;
    }
    long long totalhrs(vector<int>& v, int h) {
        long long totalhr = 0;
        int n = v.size();
        for (int i = 0; i < n; i++) {
            totalhr += ceil((double) v[i]/ (double) h);
        }return totalhr;
    }
    int minEatingSpeed(vector<int>& v, int h) {
        int low = 1;
        int high = findmax(v);
        int ans = INT_MAX;
        while (low <= high) {
            int mid = (low + high) / 2;
            long long totalhr = totalhrs(v, mid);
            if (totalhr <= h){
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }return ans;
    }
};