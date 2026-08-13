class Solution {
public:
    vector<pair<int,int>> directions = {{0,-1}, {0,1}, {1,0}, {-1,0}};
    
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        
        for (int i=0;i<grid.size();i++) {
            for (int j=0;j<grid[0].size();j++) {
                if (grid[i][j] == '1') {
                    count++;
                    dfs(i,j,grid);
                }
            }
        }

        return count;
    }

    void dfs(int i, int j, vector<vector<char>>& grid) {
        grid[i][j] = '0';
        for (const auto& d: directions) {
            int nx = i + d.first;
            int ny = j + d.second;
            if (nx >= 0 && nx < grid.size() && ny >=0 && ny < grid[0].size() && grid[nx][ny] == '1') {
                dfs(nx, ny, grid);
            }
        }
    };
};
