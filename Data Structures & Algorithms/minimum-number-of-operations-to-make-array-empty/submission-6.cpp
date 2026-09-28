class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int> f;

        for (const auto& n: nums) {
            f[n]++;
        }

        // T(x,y)=2x + 3y 
        // T(0,1) = 3
        // T(1,0) = 2
        // We can prove mathematically that every number can be represented by the above apart from 1

        // T(n) = min(T(n-2), T(n-3)) + 1
        // T(n) = 1, n=2
        // T(n) = 1, n=3
        int count = 0;
        for (const auto& [p, q]: f) {
            if (q == 1) // if fq is 1 for any number in array, only then we can't make it empty
                return -1; 
            
            unordered_map<int,int> memo;
            count += oper(q, memo);
        }

        return count;
    }

    int oper(int q, unordered_map<int,int>& memo) {
        if (q < 2) 
            return numeric_limits<int>::max();

        if (q == 2)
            return 1;

        if (q == 3)
            return 1;
        
        // this works because we've verified that q != 1
        if (memo[q] != 0)
            return memo[q];
        
        int val = min(oper(q-2, memo), oper(q-3, memo)) + 1;

        memo[q] = val;
        return val;
    }

};