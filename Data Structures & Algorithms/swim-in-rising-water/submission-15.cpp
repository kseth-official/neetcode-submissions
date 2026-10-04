class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n =grid.size();
        int l=0,r=n*n-1;
        int m;

        while (l <= r) {
            m = l + (r-l)/2;

            if (dfs(grid, m, n)) {
                r = m-1;
            } else {
                l = m+1;
            }
        }

        return l;
    }

    bool dfs(vector<vector<int>>& grid, int t, int n) {
        const vector<pair<int,int>> DIRECTIONS = {{0,1},{0,-1},{1,0},{-1,0}};
        stack<pair<int,int>> s;

        s.push({0,0});
        vector<bool> visited(n*n);

        while (!s.empty()) {
            auto [x, y] = s.top();
            s.pop();

            // skip if water level is not high enough or we've already been
            if (grid[x][y] > t || visited[y*n+x])
                continue; 

            if (x == n-1 && y == n-1)
                return true;

            visited[y*n+x]=true;

            for (const auto& [u,v]: DIRECTIONS) {
                int nx = x + u;
                int ny = y + v;

                if (nx >=0 && nx < n && ny >=0 && ny < n && grid[nx][ny] <= t) {
                    s.push({nx, ny});
                }
            }
        }

        return false;
    }
};
