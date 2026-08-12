class Solution {
public:
    int climbStairs(int n) {
        /*
            DYNAMIC PROGRAMMING
            Our recurrence is 
            T(n) = T(n-1) + T(n-2), n > 2
            T(1) = 1
            T(2) = 2

            We need to cache every T(n) we calculate to avoid repeating calculations.
        */
  
        // MEMOIZATION
        // vector<int> memo(n);
        // return helper(n, memo);

        // DP
        // vector<int> dp(n+1);
        int one = 1;
        int two = 1;
        
        for (int i = 0; i < n-1; i++) {
            int temp = one;
            one = one + two;
            two = temp;
        }

        return one;   
    }

    int helper(int n, vector<int>& memo) {
        if (n == 1) return 1;
        if (n == 2) return 2;

        if (memo[n-1] != 0) {
            return memo[n-1];
        }
        
        memo[n-1] = climbStairs(n-1) + climbStairs(n-2);

        return memo[n-1];
    }
};
