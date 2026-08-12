class Solution {
public:
    vector<int> T;

    int rob(vector<int>& nums) {
        /*
            RECURRENCE: 
            sum = nums[0], n == 1
            sum = max(nums[0],nums[1]), n == 2

            sum0 = T(i) = nums[i] + max(T(i+2), T(i+3)), n > 2, i == 0 (start at 0)
            sum1 = T(i) = nums[i] max(T(i+2), T(i+3)), n > 2, i == 0 (start at 1)

            Every time you create a new T[i], cache it

            return max(sum0,sum1)
        */

        int n = nums.size();
        if (n == 1)
            return nums[0];

        if (n == 2)
            return max(nums[0],nums[1]);

        T.resize(n+1, -1);
        
        return max(helper(0, n, nums), helper(1, n, nums));
    }

    int helper(int i, int n, vector<int>& nums) {
        if (i >= n)
            return 0;
        
        if (T[i] == -1)
            T[i] = nums[i] + max(helper(i+2,n,nums), helper(i+3,n,nums));
        
        return T[i];
    }
};
