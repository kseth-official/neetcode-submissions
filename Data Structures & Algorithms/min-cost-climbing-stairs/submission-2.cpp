class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n);

        int c0 = cost[0];
        int c1 = cost[1];
        
        
        int c2;
        for (int i=2;i<n;i++) {
            c2 = min(c1,c0) + cost[i];
            c0 = c1;
            c1 = c2;
        }

        return min(c1, c0);
    }
};
