class Solution {
public:
    int count = 0;
    vector<pair<int,int>> directions = {{0,-1}, {0,1}, {1,0}, {-1,0}};
    
    int numIslands(vector<vector<char>>& grid) {
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
            int new_x = i + d.first;
            int new_y = j + d.second;
            if (new_x >= 0 && new_x < grid.size() && new_y >=0 && new_y < grid[0].size() && grid[new_x][new_y] == '1') {
                dfs(new_x, new_y, grid);
            }
        }
    };
};
