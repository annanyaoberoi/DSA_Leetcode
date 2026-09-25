class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;
        int res = 0;
        for (int i = 0; i < height.size(); i++) {
            int area = (r - l) * min (height[l], height[r]);
            res = max(res, area);
            if(height[l] < height[r]) l++;
            else r--;
        }return res;
    }
};