class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1)
            return nums[0];

        return max(robWindow(0,nums.size()-2,nums), robWindow(1,nums.size()-1,nums));
    }

    int robWindow(int sIdx, int eIdx, vector<int>& nums) {
        int winLength = eIdx-sIdx+1;
        if (winLength == 1) 
            return nums[sIdx];

        if (winLength == 2) {
            return max(nums[sIdx],nums[sIdx+1]);
        }

        // represents i-2th index
        int dp0 = nums[sIdx];
        // represents i-1th index
        int dp1 = max(nums[sIdx],nums[sIdx+1]);
        // represents ith index
        int dp2;

        for (int i=sIdx+2;i<=eIdx;i++) {
            dp2 = max(nums[i] + dp0, dp1);
            dp0 = dp1;
            dp1 = dp2;
        }

        return dp2;
    }
};
