class Solution {
public:
    int perimeter = 0;
    vector<pair<int,int>> directions = {{0,1}, {0,-1}, {1,0}, {-1,0}};
    int islandPerimeter(vector<vector<int>>& grid) {
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        for (int i=0;i<grid.size();i++) {
            for (int j=0;j<grid[0].size();j++) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    visited[i][j] = true;
                    dfs(grid, i, j, visited);
                }    
            }
        }

        return perimeter;
    }

    void dfs(vector<vector<int>>& grid, int i, int j, vector<vector<bool>>& visited) {
        for (const auto& dir: directions) {
            int nx = i + dir.first;
            int ny = j + dir.second;
            if (nx < 0 || nx >= grid.size() || ny < 0 || ny >= grid[0].size() || grid[nx][ny] == 0) {
                perimeter++;
                continue;
            }

            if (nx >= 0 && nx < grid.size() && ny >= 0 && ny < grid[0].size() && grid[nx][ny] == 1 && visited[nx][ny] == false) {
                visited[nx][ny] = true;
                dfs(grid, nx, ny, visited);
            }
        }
    }
};