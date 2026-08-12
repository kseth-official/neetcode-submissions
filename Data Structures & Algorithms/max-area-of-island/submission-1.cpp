class Solution {
public:
    vector<pair<int,int>> DIRECTIONS = {
        {1,0},
        {0,1},
        {-1,0},
        {0,-1}
    };

    int largestArea = 0;

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();

        for (int i=0;i<r;i++) {
            for (int j=0;j<c;j++) {
                if (grid[i][j] == 1) {
                    search(grid, i, j);
                }
            }
        }

        return largestArea;
    }

    void search(vector<vector<int>>& grid, int r, int c) {
        stack<pair<int,int>> q;
        q.push({r,c});
        grid[r][c] = 0;
        int islandArea = 1;
        largestArea = max(largestArea, islandArea);
        
        while (!q.empty()) {
            auto node = q.top();
            q.pop();

            for (const auto& direction: DIRECTIONS) {
                int nr = node.first + direction.first;
                int nc = node.second + direction.second;

                if (0 <= nr && 0 <= nc && nr < grid.size() && nc < grid[0].size() && grid[nr][nc] == 1) {
                    q.push({nr,nc});
                    grid[nr][nc] = 0;
                    islandArea++;
                }
            }

            largestArea = max(largestArea, islandArea);
        }
    }
};