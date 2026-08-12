class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        // T: O(n)
        // S: O(1)

        int dp0 = cost[0];
        int dp1 = cost[1];
        
        int dp2;
        for (int i=2;i<cost.size();i++) {
            dp2 = min(dp0,dp1) + cost[i];
            dp0 = dp1;
            dp1 = dp2;
        }

        return min(dp1, dp0);
    }
};
