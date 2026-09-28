class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int> ps(nums.size());
        ps[0] = nums[0];
        for (int i=1;i<nums.size();i++) {
            ps[i]=ps[i-1] + nums[i];
        }

        int ls, rs; 
        for (int i=0;i<nums.size();i++) {
            if (i == nums.size()-1) {
                rs = 0;
            } else {
                rs = ps[nums.size()-1] - ps[i];
            }

            if (i == 0) {
                ls = 0;
            } else {
                ls = ps[i-1];
            }
            if (ls == rs)
                return i;
        }

        return -1;
    }
};