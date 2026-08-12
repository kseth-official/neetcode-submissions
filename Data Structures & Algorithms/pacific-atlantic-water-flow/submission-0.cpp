class Solution {
public:
    const vector<pair<int,int>> DIRECTIONS = {
        {1 , 0},  // RIGHT
        {-1, 0},  // LEFT
        {0 ,-1},  // UP
        {0 , 1},  // DOWN
    };

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int ROWS = heights.size();
        int COLS = heights[0].size();

        vector<vector<bool>> pac(ROWS, vector<bool>(COLS, false));
        vector<vector<bool>> atl(ROWS, vector<bool>(COLS, false));
        
        queue<pair<int,int>> pacQ;
        queue<pair<int,int>> atlQ;

        // oops forgot to create the initial queues representing the valid positions
        for (int i=0;i<ROWS;i++) {
            pacQ.push({i,0});
            atlQ.push({i,COLS-1});
        }

        for (int i=0;i<COLS;i++) {
            pacQ.push({0,i});
            atlQ.push({ROWS-1,i});
        }

        bfs(pacQ,pac,ROWS,COLS,heights);
        bfs(atlQ,atl,ROWS,COLS,heights);

        vector<vector<int>> solution;
        for (int i=0;i<ROWS;i++) {
            for (int j=0;j<COLS;j++) {
                if (pac[i][j] && atl[i][j])
                    solution.push_back({i,j});
            }
        }

        return solution;
    }

    void bfs(queue<pair<int,int>>& q, vector<vector<bool>>& ocean, int ROWS, int COLS, vector<vector<int>>& heights) {
        // TODO: Implement BFS where if starting from member of queue,
        // we can reach a particular tile moving up the mountain (height is greater than or equal for new tile),
        // then tile can be reached by from that particular ocean, therefore, it should be set to true.

        while (!q.empty()) {
            auto& [r,c] = q.front(); q.pop();
            ocean[r][c] = true;

            for (const auto& direction: DIRECTIONS) {
                int nr = r + direction.first;
                int nc = c + direction.second;

                // if within bounds and not already true for ocean and height is >= current height, add to queue
                if (nr >= 0 && nr < ROWS && nc >= 0 && nc < COLS && ocean[nr][nc] == false && heights[nr][nc] >= heights[r][c]) {
                    q.push({nr,nc});
                }
            }
        }
    }
};
