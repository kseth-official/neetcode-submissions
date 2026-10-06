class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp;

        for (int i=0;i<nums.size();i++) {
            if (dp.empty() || nums[i] > dp.back()) {
                dp.push_back(nums[i]);
            }

            int l=0,r=dp.size()-1;
            while (l<=r) {
                int m = l + (r-l)/2;

                if (dp[m] >= nums[i]) {
                    // go left
                    r = m-1;
                } else {
                    // go right
                    l = m+1;
                }
            }

            dp[l]=nums[i];
        }

        return dp.size();
    }
};