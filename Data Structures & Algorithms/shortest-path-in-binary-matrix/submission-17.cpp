class Solution {
public:
    const vector<pair<int,int>> DIRECTIONS = {{0,1},{0,-1},{1,0},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n-1][n-1] == 1)
            return -1;

        queue<tuple<int,int,int>> q;

        q.push({0,0,1});
        grid[0][0]=1;
        
        while (!q.empty()) {
            auto [i, j, d] =q.front();
            q.pop();

            // BFS Guarantees We Reached Earliest
            if (i == n-1 && j == n-1)
                return d;
            
            for (const auto& dir: DIRECTIONS) {
                int nx = i + dir.first;
                int ny = j + dir.second;

                if (nx < 0 || nx >=n || ny < 0 || ny >= n)
                    continue;
                
                if (grid[nx][ny] == 1)
                    continue;
                
                int nd = 1 + d;

                q.push({nx, ny, nd});
                grid[nx][ny] = 1;
            }
        }

        return -1; 
    }
};