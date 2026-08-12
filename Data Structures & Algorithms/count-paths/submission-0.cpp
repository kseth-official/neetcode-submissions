class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m == 1 || n == 1)
            return 1;

        vector<vector<int>> T(m, vector<int>(n));

        T[m-1][n-1] = 1;

        for (int i = m-1; i >=0; i--) {
            for (int j = n-1; j >=0; j--) {
                if (i == m-1 && j == n-1)
                    continue;
                
                if (i == m-1) {
                    T[i][j]=T[i][j+1];
                } else if (j == n-1) {
                    T[i][j]=T[i+1][j];
                } else {
                    T[i][j]=T[i+1][j]+T[i][j+1];
                }
            }
        }

        return T[0][0];
    }
};
