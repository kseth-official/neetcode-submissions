class Solution {
public:
    int c_ins = 1, c_del = 1, c_rep = 1;

    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> tableau(n+1,vector<int>(m+1,-1));

        // Filling in row 0 and column 0 (word1=source, word2=target)
        for(int i = 0; i < n+1; i++) 
            tableau[i][0] = i*c_del;
        for(int j = 1; j < m+1; j++) 
            tableau[0][j] = j*c_ins;

        for (int i = 1; i < n+1; i++) {
            for (int j = 1; j < m+1; j++) {
                tableau[i][j] = findDistance(tableau, word1, word2, i, j);
            }
        }

        return tableau[n][m];
    }

    int findDistance(const vector<vector<int>>& tableau, string& w1, string& w2, int i, int j) {
        if (w1[i-1] == w2[j-1]) {
            return min(tableau[i-1][j-1], min(tableau[i][j-1] + c_ins, tableau[i-1][j] + c_del));
        } 
        return min(tableau[i-1][j-1] + c_rep, min(tableau[i][j-1] + c_ins, tableau[i-1][j] + c_del));
    }
};