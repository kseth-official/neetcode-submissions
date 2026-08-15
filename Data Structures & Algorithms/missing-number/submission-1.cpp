class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res = nums.size(); // start with n because i in [0..n-1]
        for (int i=0;i<nums.size();i++) {
            res ^= i ^ nums[i];
        }
        return res;
    }
};
