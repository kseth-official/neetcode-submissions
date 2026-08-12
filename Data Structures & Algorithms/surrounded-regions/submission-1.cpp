class Solution {
public:
    const vector<pair<int,int>> DIRECTIONS = {
        {1,0},
        {-1,0},
        {0,-1},
        {0,1},
    };

    void solve(vector<vector<char>>& board) {
        /*
            Add every not surrounded tile (every O on a border)
            to our BFS queue.

            Start BFS from each, marking Os that can be reached as not surrounded.

            While doing BFS, if you encounter a tile already marked as not surrounded, ignore that path.

            Iterate over all tiles on board, marking tiles not in not surrounded as X, if an O        
        */
        int ROWS = board.size();
        int COLS = board[0].size();
        
        queue<pair<int,int>> q;

        for (int i=0;i<ROWS;i++) {
            if (board[i][0] == 'O')
                q.push({i,0});
            if (board[i][COLS-1] == 'O')
            q.push({i,COLS-1});
        }

        for (int i=1;i<COLS-1;i++) {
            if (board[0][i] == 'O')
                q.push({0,i});
            if (board[ROWS-1][i] == 'O')
                q.push({ROWS-1,i});
        }

        unordered_map<int,unordered_set<int>> not_surrounded;

        while (!q.empty()) {
            auto pos = q.front(); q.pop();
            int r = pos.first;
            int c = pos.second;

            not_surrounded[r].insert(c);

            for (const auto& direction: DIRECTIONS) {
                int nr = r + direction.first;
                int nc = c + direction.second;

                if (nr >= 0 && nc >= 0 && nr < ROWS && nc < COLS && board[nr][nc] == 'O' && not_surrounded[nr].find(nc) == not_surrounded[nr].end()) {
                    q.push({nr,nc});
                }
            }
        }

        for (int i=0;i<ROWS;i++) {
            for (int j=0;j<COLS;j++) {
                if (board[i][j] == 'O' && not_surrounded[i].find(j) == not_surrounded[i].end())
                    board[i][j] = 'X';
            }
        }
    }
};
