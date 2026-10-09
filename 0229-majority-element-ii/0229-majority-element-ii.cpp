class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int eo = 0, co = 0, et = 0, ct = 0;
        for (int  i = 0; i < nums.size(); i++) {
            if (co == 0 && nums[i] != et) {
                co = 1;
                eo = nums[i];
            }
            else if (ct == 0 && nums[i] != eo) {
                ct = 1;
                et = nums[i];
            }
            else if (eo == nums[i]) co++;
            else if (et == nums[i]) ct++;
            else co--, ct--;
        }
        vector <int> res;
        co = 0, ct = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (eo == nums[i]) co++;
            else if (et == nums[i]) ct++;
        }
        int mini = (int) (nums.size() / 3) + 1;
        if (co >= mini) res.push_back(eo);
        if (ct >= mini) res.push_back(et);
                return res;
    }
};