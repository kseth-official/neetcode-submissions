class Solution {
public:
    const pair<int,int> U = {0, -1};
    const pair<int,int> D = {0,  1};
    const pair<int,int> L = {-1, 0};
    const pair<int,int> R = {1,  0};
    const vector<pair<int,int>> DIRECTIONS = {
        U,
        D,
        L,
        R,
    };

    int islandPerimeter(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        // using BFS
        queue<pair<int,int>> q;
        bool flag = true;

        for (int i=0;i<grid.size();i++) {
            if (!flag)
                break;
            for (int j=0;j<grid[0].size();j++) {
                if (grid[i][j] == 1) {
                    q.push({i,j}); 
                    visited[i][j]=true;
                    flag = false;                    
                    break;
                }
            }
        }

        int perimeter = 0;

        while (!q.empty()) {
            auto pos = q.front();
            q.pop();

            for (const auto& d: DIRECTIONS) {
                int x = pos.first + d.first;
                int y = pos.second + d.second;

                if (isValidPosition({x,y}, rows, cols) && grid[x][y] == 1) {
                    // is land
                    if (!visited[x][y]) {
                        q.push({x,y});
                        visited[x][y] = true;
                    }
                } else {
                    // is water or out of bounds
                    perimeter++;
                }
            }
        }

        return perimeter;
    }

    bool isValidPosition(const pair<int,int>& p, int rows, int cols) {
        int x = p.first;
        int y = p.second;
        if (x < 0 || x >= rows)
            return false;
        if (y < 0 || y >= cols)
            return false;
        return true;
    }
};