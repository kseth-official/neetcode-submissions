class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> solution;
        for (int i = 0; i <= n; i++) {
            solution.push_back(__builtin_popcount(i));
        }
        return solution;
    }
};
