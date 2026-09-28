class Solution {
public:
    int maxArea(vector<int>& height) {
        int low = 0;
        int high = height.size() - 1;
        int res = 0;
        for (int i = 0; i < height.size(); i++) {
            int area = (high - low) * min (height[low], height[high]);
            res = max (res, area);
            if (height[low] < height[high]) low++;
            else high--;
        }return res;
    }
};