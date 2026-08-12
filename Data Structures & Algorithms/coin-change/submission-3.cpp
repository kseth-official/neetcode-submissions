class Solution {
public:
    unordered_map<int,int> memo;

    int coinChange(vector<int>& coins, int amount) {
        // maps amount to number of coins needed
        // expand tree by subtracting each of coins from amount
        // we need to use a bottom up approach that adds number of coins
        // needed for each node using the nodes below it
        // we cache number of coins needed for a node in case the computation
        // comes up again
        // therefore, in the worst case, we do amount number of possible additions
        // log_{coins.size()}(amount) number of additions
        return helper(coins, amount);
    }

    int helper(vector<int>& coins, int amount) {
        if (amount == 0)
            return 0;
        if (amount < 0) {
            memo[amount] = -1;
            return -1;
        }

        int smallest = 10001;
        for (int i=0;i<coins.size();i++) {
            int remaining = amount-coins[i];
            if (memo.find(remaining) == memo.end()) {
                int value = helper(coins, remaining);
                if (value != -1) {
                    smallest = min(smallest, 1 + value);
                }
            } else {
                int value = memo[remaining];
                if (value != -1)
                    smallest = min(smallest, 1+value);
            }
        }

        if (smallest == 10001) {
            memo[amount] = -1;
            smallest = -1;
        }

        memo[amount] = smallest;
            
        return smallest;
    }
};
