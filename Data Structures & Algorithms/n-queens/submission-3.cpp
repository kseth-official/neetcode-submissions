class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> sols;
        vector<string> board(n, string(n, '.'));
        backtrack(n, 0, board, sols);
        return sols;
    }

    void backtrack(int n, int row, vector<string>& board, vector<vector<string>>& result) {
        if (row == n) {
            result.push_back(board);
            return;
        }
        
        for (int col=0;col<n;col++) {
            if (isSafe(row, col, board)) {
                board[row][col] = 'Q'; // place
                backtrack(n, row+1, board, result); // explore
                board[row][col] = '.'; // backtrack (undo)
            }
        }
    }

    // 6*n checks for if a position is safe
    bool isSafe(int r, int c, vector<string>& board) {
        // check row
        for (int i=0;i<board.size();i++) {
            if (board[i][c] == 'Q')
                return false;
        }

        // check col
        for (int j=0;j<board[0].size();j++) {
            if (board[r][j] == 'Q')
                return false;
        }

        // down right diagonal
        for (int i=r,j=c;i<board.size() && j < board[0].size();i++, j++) {
            if (board[i][j] == 'Q')
                return false;
        }

        // up right diagonal
        for (int i=r,j=c;i<board.size() && j >= 0; i++, j--) {
            if (board[i][j] == 'Q')
                return false;
        }

        // up left diagonal
        for (int i=r,j=c;i>=0 && j>=0;i--, j--) {
            if (board[i][j] == 'Q')
                return false;
        }
        
        // down left diagonal
        for (int i=r,j=c;i>=0 && j<board.size();i--, j++) {
            if (board[i][j] == 'Q')
                return false;
        }

        return true;
    }
};
