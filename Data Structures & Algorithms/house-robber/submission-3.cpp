class Solution {
public:
    int rob(vector<int>& nums) {
        // if (nums.size() == 1) 
        //     return nums[0];

        // if (nums.size() == 2) {
        //     return max(nums[0],nums[1]);
        // }

        // vector<int> dp(nums.size());

        // dp[0] = nums[0];
        // dp[1] = max(nums[0],nums[1]);
 
        // for (int i=2;i<nums.size();i++) {
        //     dp[i] = max(nums[i] + dp[i-2], dp[i-1]);
        // }

        // return dp[nums.size()-1];

        if (nums.size() == 1) 
            return nums[0];

        if (nums.size() == 2) {
            return max(nums[0],nums[1]);
        }

        // represents i-2th index
        int dp0 = nums[0];
        // represents i-1th index
        int dp1 = max(nums[0],nums[1]);
        // represents ith index
        int dp2;

        for (int i=2;i<nums.size();i++) {
            dp2 = max(nums[i] + dp0, dp1);
            dp0 = dp1;
            dp1 = dp2;
        }

        return dp2;
    }
};
