class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();

        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

        for (int i=m-1;i>=0;i--) {
            for (int j=n-1;j>=0;j--) {
                if (text1[i] == text2[j]) {
                    dp[i][j]=1+dp[i+1][j+1];
                } else {
                    dp[i][j]=max(dp[i+1][j], dp[i][j+1]);
                }
            }
        }

        return dp[0][0];
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
