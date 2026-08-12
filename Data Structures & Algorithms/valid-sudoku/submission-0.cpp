class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> current_set;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (current_set.find(board[i][j]) != current_set.end() && board[i][j] != '.')
                    return false;
                current_set.insert(board[i][j]);
            }
            current_set.clear();
        }

        for (int j = 0; j < board[0].size(); j++) {
            for (int i = 0; i < board.size(); i++) {           
                if (current_set.find(board[i][j]) != current_set.end() && board[i][j] != '.')
                    return false;
                current_set.insert(board[i][j]);
            }
            current_set.clear();
        }


        vector<pair<int,int>> index_pairs = {
            {3,3},
            {6,3},
            {9,3},
            {3,6},
            {6,6},
            {9,6},
            {3,9},
            {6,9},
            {9,9}
        };

        for (const auto& pair : index_pairs) {
            int start_index_x = pair.first-3;
            int end_index_x = pair.first;
            int start_index_y = pair.second-3;
            int end_index_y = pair.second;

            for (int i = start_index_x; i < end_index_x; i++) {
                for (int j = start_index_y; j < end_index_y; j++) { 
                    if (current_set.find(board[i][j]) != current_set.end() && board[i][j] != '.')
                        return false;
                    current_set.insert(board[i][j]);
                }   
            }

            current_set.clear();
        }
        
        return true;
    }
};
