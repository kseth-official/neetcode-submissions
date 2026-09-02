class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<bool> visited(points.size());
        int count = 0;
        int res = 0;
         

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        pq.push({0,0});

        while (count < points.size()) {
            auto [wt, p] = pq.top();
            pq.pop();

            if (visited[p])
                continue;
            
            res += wt;
            visited[p] = true;
            count++;

            for (int j=0;j<points.size();j++) {
                if (!visited[j]) {
                    pq.push({dis(points[p][0], points[p][1], points[j][0], points[j][1]), j});
                }
            }
        }

        return res;
    }

    int dis(int x1, int y1, int x2, int y2) {
        return abs(x1-x2) + abs(y1-y2);
    }
};
