class Solution {
public:
    const vector<pair<int,int>> DIRECTIONS = {{0,1},{0,-1},{1,0},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n-1][n-1] == 1)
            return -1;
        
        vector<int> distances(n*n, numeric_limits<int>::max());
        auto cmp = [](pair<int,int>& a, pair<int,int>& b) {
            return (b.second - a.second) * (b.second - a.second) + (a.first - b.first) * (a.first - b.first);
        };

        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)> s;

        s.push({0,0});
        distances[0] = 1;
        while (!s.empty()) {
            auto [i, j] = s.top();
            s.pop();
            
            for (const auto& d: DIRECTIONS) {
                int nx = i + d.first;
                int ny = j + d.second;

                if (nx < 0 || nx >=n || ny < 0 || ny >= n)
                    continue;
                
                if (grid[nx][ny] == 1)
                    continue;
                
                int nd = 1 + distances[i + n*j];

                if (nd < distances[nx + n*ny]) {
                    distances[nx + n*ny] = nd;
                    s.push({nx, ny});
                }
            }
        }

        return distances[n*n-1] == numeric_limits<int>::max() ? -1 : distances[n*n-1];
    }
};