class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        // T: O(n)
        // S: O(1)

        int c0 = cost[0];
        int c1 = cost[1];
        
        int c2;
        for (int i=2;i<cost.size();i++) {
            c2 = min(c0,c1) + cost[i];
            c0 = c1;
            c1 = c2;
        }

        return min(c1, c0);
    }
};
