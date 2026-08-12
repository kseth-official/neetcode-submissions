class Solution {
public:
    vector<int> steps;

    int climbStairs(int n) {
        /*
            DYNAMIC PROGRAMMING
            Our recurrence is 
            T(n) = T(n-1) + T(n-2), n > 2
            T(1) = 1
            T(2) = 2

            We need to cache every T(n) we calculate to avoid repeating calculations.
        */

        
        // NAIVE APPROACH
        if (n == 1) return 1;
        if (n == 2) return 2;
        return climbStairs(n-1) + climbStairs(n-2);
    }
};
