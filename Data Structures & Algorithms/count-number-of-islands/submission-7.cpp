class Solution {
public:
    const vector<pair<int,int>> DIRECTIONS = {
        {1, 0},
        {0, 1},
        {-1, 0},
        {0, -1}
    };

    int numIslands(vector<vector<char>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        int numIslands = 0;

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == '1') {
                    search<queue<pair<int,int>>>(grid, i, j); // Change this line if you want to use queue or stack
                    numIslands++;
                }
            }
        }

        return numIslands;
    }

    template <typename T>
    void search(vector<vector<char>>& grid, int r, int c) {
        T q;
        grid[r][c] = '0';
        q.push({r, c});

        while (!q.empty()) {
            pair<int,int> node;
            if constexpr (std::is_same<T, stack<pair<int,int>>>::value) {
                node = q.top();
            } else {
                node = q.front();
            }

            q.pop();

            for (const auto& direction : DIRECTIONS) {
                int nr = node.first + direction.first;
                int nc = node.second + direction.second;
                if (0 <= nr && nr < grid.size() && 0 <= nc && nc < grid[0].size() && grid[nr][nc] == '1') {
                    q.push({nr, nc});
                    grid[nr][nc] = '0';
                }
            }
        }
    }
};
