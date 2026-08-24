class Solution {
public:
    int totaldays(vector<int>& weights, int capacity) {
        int day = 1;
        int load = 0;
        for (int i = 0; i < weights.size(); i++) {
            if (weights[i] + load > capacity) {
                day += 1;
                load = weights[i];
            }
            else load += weights[i];
        }return day;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int maxi = INT_MIN;
        int sum = 0;
        for (int i = 0; i < weights.size(); i++) {
            maxi = max(maxi, weights[i]);
            sum += weights[i];
        }
        int low = maxi;
        int high = sum;
        while (low <= high) {
            int mid = (low + high) / 2;
            int noofdays = totaldays(weights, mid);
            if (noofdays <= days) high = mid - 1;
            else low = mid + 1;
        }return low;
    }
};