class Solution {
public:
    int totaldays(int capacity, vector<int> &weights) {
        int days = 1;
        int load = 0;
        for (int i = 0;  i < weights.size(); i++) {
            if (weights[i] + load > capacity) {
                days++;
                load = weights[i];
            }
            else {
                load += weights[i];
            }
        }return days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int maxi = INT_MIN;
        int sum = 0;
        for (int i = 0; i < weights.size(); i++) {
            sum += weights[i];
            maxi = max(maxi, weights[i]);
        }
        int low = maxi;
        int high = sum;
        while (low <= high) {
            int mid = (low + high) / 2;
            int noofdays = totaldays(mid, weights);
            if (noofdays <= days) {
                high = mid - 1;
            }
            else low = mid + 1; 
        }return low;
    }
};