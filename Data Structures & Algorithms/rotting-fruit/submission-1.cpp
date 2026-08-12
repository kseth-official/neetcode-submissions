class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        // SIMULTANEOUS BFS STARTING AT ALL ROTTEN FRUIT.
        int rows = grid.size();
        int cols = grid[0].size();
        int fresh = 0;
        int time = 0;
        
        queue<pair<int,int>> q;

        for (int i=0;i<rows;i++) {
            for (int j=0;j<cols;j++) {
                if (grid[i][j] == 2)
                    q.push({i,j});

                if (grid[i][j] == 1)
                    fresh++;
            }
        }

        vector<pair<int,int>> directions = {
            {0,1},
            {1,0},
            {-1,0},
            {0,-1}
        };

        while (fresh > 0 && !q.empty()) {
            int sim_step_size = q.size();

            for (int i=0;i<sim_step_size;i++) {
                int r = q.front().first;
                int c = q.front().second;

                q.pop();

                for (const auto& direction: directions) {
                    int nr = r + direction.first;
                    int nc = c + direction.second;

                    if (nr < 0 || nc < 0 || nr >=rows || nc >= cols || grid[nr][nc] != 1) continue;

                    grid[nr][nc] = 2;
                    fresh--;
                    q.push({nr,nc});
                } 
            }

            time++;
        }

        return fresh == 0 ? time : -1;
    }
};
