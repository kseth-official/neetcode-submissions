class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int l=0, r=n*n-1, m;

        while (l <= r) {
            m = l + ((r-l) & 1);

            auto res = dfs(grid, m, n);
            if (res) {
                r = m-1;
                // go left
            } else { 
                l = m+1;
                // go right
            }
        }

        // no solution
        return l;
    }

    const vector<pair<int,int>> DIRECTIONS = {{0,1}, {0,-1}, {1,0}, {-1,0}}; 

    bool dfs(vector<vector<int>>& grid, int h, int n) {
        if (grid[0][0] > h)
            return false;
        // return true if dest reachable, otherwise ret false
        vector<bool> visited(n*n);
        
        stack<pair<int,int>> s;
        s.push({0,0});
        while (!s.empty()) {
            auto t = s.top();
            s.pop();

            if (visited[t.first + n*t.second])
                continue;
                
            if (t.first == n-1 && t.second == n-1)
                return true;

            visited[t.first + n*t.second] = true;

            for (const auto& dir: DIRECTIONS) {
                int nx = t.first + dir.first;
                int ny = t.second + dir.second;
                
                if (nx>=0 && nx < n && ny >=0 && ny < n && grid[nx][ny] <= h) {
                    s.push({nx,ny});
                }
            }
        }
        return false;
    }
};
