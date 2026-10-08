class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        if (text1.size() < text2.size())
            return longestCommonSubsequence(text2,text1);

        vector<vector<int>> memo(text1.size(), vector<int>(text2.size(), -1));

        return dfs(text1,text2,0,0,memo);
    }

    int dfs(string& s1, string& s2, int i, int j, vector<vector<int>>& memo) { 
        // reached past end of either string
        if (i >= s1.size() || j >= s2.size())
            return 0;
        
        if (memo[i][j] != -1) {
            return memo[i][j]; 
        }

        int res;
        if (s1[i] == s2[j])
            res = 1 + dfs(s1, s2, i+1,j+1,memo);
        else
            res = max(dfs(s1,s2,i,j+1,memo), dfs(s1,s2,i+1,j,memo));
        
        memo[i][j] = res;

        return res;
    }
};
