class Solution {
   public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // Use Djikstra's Algorithm to find the maximum of the minimum distances

        unordered_map<int, vector<pair<int,int>>> adj_list;

        for (int i = 0; i < times.size(); i++) {
            adj_list[times[i][0]].push_back({times[i][1], times[i][2]});
        }

        int int_max = numeric_limits<int>::max();
        vector<int> distances(n, int_max);
        distances[k-1]=0;

        // min-heap of shortest distances to every vertex
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> q;
        q.push({k, 0});

        while (!q.empty()) {
            auto [ui, d] = q.top();
            q.pop();

            // -1 adjustment since the nodes are 1 indexed while distances are 0 indexed
            // the distance so far is greater than the shortest known distance, so skip this
            // by popping and deleting the entry
            if (d > distances[ui - 1]) {
                continue;
            }

            for (const auto& [vi, ti]: adj_list[ui]) {
                int new_dist = distances[ui-1] + ti;
                if (new_dist < distances[vi-1]) {
                    distances[vi-1] = new_dist;
                    q.push({vi, new_dist});
                }
            }
        }

        // If maximum minimum distance to a node is infinite, it means that node was unreachable so its distance was never updated
        int result = -1;
        for (const auto& dist: distances) {
            if (dist == int_max)
                return -1;
            result = max(result, dist);
        }
        
        return result; 
    }
};
