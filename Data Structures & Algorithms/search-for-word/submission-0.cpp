class Solution {
public:
    set<pair<int,int>> path;

    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (dfs(board,0,i,j,word)) {
                    return true;
                }
            }
        }
        
        return false;
    }

    bool dfs(vector<vector<char>>& board, int i, int r, int c, const string& word) {
        int n_rows = board.size();
        int n_cols = board[0].size();

        if (i == word.length())
            return true;

        if (r >= n_rows || r < 0 || c >= n_cols || c < 0 || path.count({r,c}) || board[r][c] != word[i])
            return false;

        path.insert({r,c});
        auto result = 
        dfs(board,i+1,r+1,c,word) || 
        dfs(board,i+1,r-1,c,word) ||
        dfs(board,i+1,r,c+1,word) ||
        dfs(board,i+1,r,c-1,word);

        path.erase({r,c});

        return result;
    }
};