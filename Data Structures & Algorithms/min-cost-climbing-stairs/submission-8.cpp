class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        // min cost from step i = cost of i + min(min cost from step i + 1, min cost from step i + 2). min cost from n-1 = cost[n-1], min cost from n-2 = cost[n-2]
        int n = cost.size();
        int dpn = cost[n-1], dpn1 = cost[n-2];

        for (int i = n-3;i>=0;i--) {
            int c = cost[i] + min(dpn, dpn1);
            dpn = dpn1;
            dpn1 = c;
        } 

        return min(dpn, dpn1);
    }
};