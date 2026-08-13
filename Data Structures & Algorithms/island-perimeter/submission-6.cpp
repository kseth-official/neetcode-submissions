class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
    int res = 0;
    for (int r = 0; r < grid.size(); r++) {
        for (int c = 0; c < grid[0].size(); c++) {
            if (grid[r][c]) {
                res += 4;
                // Only check up and left to avoid counting edges twice
                if (r && grid[r-1][c]) res -= 2;
                if (c && grid[r][c-1]) res -= 2;
            }
        }
    }
    return res;
}
};