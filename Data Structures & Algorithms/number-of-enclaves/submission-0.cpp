class Solution {
public:
    int result = 0;
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        for (int i=1;i<m-1;i++) {
           for (int j=1;j<n-1;j++) {
                if (grid[i][j] == 1) {
                    result++;
                    dfs(i,j,grid,m,n);
                }
           } 
        }  
        return result;
    }

    const vector<pair<int,int>> directions = {{0,1},{0,-1},{1,0},{-1,0}};
    void dfs(int i,int j, vector<vector<int>>& grid, int m, int n) {
        vector<bool> visited(m*n);

        stack<pair<int,int>> s;
        s.push({i,j});
        while (!s.empty()) {
            auto [x,y] = s.top();

            s.pop();

            if (visited[x * m + y])
                continue;
            
            visited[x*m+y]=true;
            
            for (const auto& d: directions) {
                int nx = x + d.first;
                int ny = y + d.second;

                if (nx < 0 || nx >= m || ny < 0 || ny >= n) {
                    result--;
                    return;
                }

                if (grid[nx][ny] == 1)
                    s.push({nx, ny});
            }
        }
    }
};