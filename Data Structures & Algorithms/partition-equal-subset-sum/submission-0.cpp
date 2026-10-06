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

        unordered_set<int> sums;
        sums.insert(nums[0]);
        sums.insert(0);
        for (int i=1;i<nums.size();i++) {
            int val = nums[i];
            vector<int> temp;
            for (const auto& sum: sums) {
                int newSum = sum+val;
                if (newSum == tar)
                    return true;
                if (sums.count(newSum) == 0)
                    temp.push_back(newSum);
            }
            sums.insert(temp.begin(), temp.end());
        }

        return false;
    }
};
