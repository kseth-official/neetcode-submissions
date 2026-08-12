class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> solution(n+1,0);
        for (int i = 0; i <= n; i++) {
            solution[i]=__builtin_popcount(i);
        }
        return solution;
    }
};
