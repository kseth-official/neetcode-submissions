class Solution {
public:
    bool canPartition(vector<int>& nums) {
        /*
            Number of ways to partition:

            n = 4
            For each of n elements, there are 2 choices. Assign
            to set A or set B in an ordered way

            2^n

            However, {A, B} = {B, A}, so divide by 2

            Therefore,
            2^(n-1) unique partitions can be created

            n = 4
            2^3 = 8
            1 + 4 + 3 = 8

            { } {1 2 3 4}
            {1} {2 3 4}
            {2} {1 3 4}
            {3} {1 2 4}
            {4} {1 2 3}
            {1 2} {3 4}
            {1 3} {2 4}
            {2 3} {4 1}

            This gives brute force approach a O(2^n)

            Find a way to compute subproblems and reuse items of tree

            Compute a decision tree where we choose to include or not include, and save solutions bottom up
        */
        int tar=0;
        for (const auto& num: nums) {
            tar+=num;
        }

        if ((tar & 1) != 0)
            return false;

        tar/=2;
        int n = nums.size();

        vector<bool> dp(tar+1,false);
        dp[0]=true;

        for (int i=0;i<n;i++) {
            for (int j=tar;j>=nums[i];j--) {
                dp[j] = dp[j] || dp[j - nums[i]];
            }
        }

        return dp[tar];
    }
};
