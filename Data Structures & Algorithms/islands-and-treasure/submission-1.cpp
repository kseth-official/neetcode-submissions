class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        // MULTISOURCE BFS SOLUTION
        int ROWS = grid.size();
        int COLS = grid[0].size();

        queue<pair<int,int>> q;

        for (int i=0;i<ROWS;i++) {
            for (int j=0;j<COLS;j++) {
                if (grid[i][j] == 0)
                    q.push({i,j});
            }
        }   

        vector<pair<int,int>> directions = {
            {1,0},
            {0,1},
            {-1,0},
            {0,-1}
        };


        while (!q.empty()) {
            int cr = q.front().first;
            int cc = q.front().second;

            q.pop();

            for (const auto& direction: directions) {
                int nr = cr + direction.first;
                int nc = cc + direction.second;

                if (nr < 0 || nr >= ROWS || nc < 0 || nc >= COLS || grid[nr][nc] != INT_MAX) continue;

                grid[nr][nc] = grid[cr][cc] + 1;
                q.push({nr,nc});
            }
        }
    }
};
