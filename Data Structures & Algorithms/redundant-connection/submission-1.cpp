class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> adj_list(n + 1);
        for (const auto& edge : edges) {
            adj_list[edge[0]].push_back(edge[1]);
            adj_list[edge[1]].push_back(edge[0]);
        }

        stack<int> s;
        vector<bool> visited(n + 1, false);
        vector<int> parent(n + 1, -1);
        s.push(edges[0][0]);

        while (!s.empty()) {
            int top = s.top();
            s.pop();

            if (!visited[top]) {
                visited[top] = true;
                for (const auto& neighbour : adj_list[top]) {
                    if (!visited[neighbour]) {
                        parent[neighbour] = top;
                        s.push(neighbour);
                    } else if (neighbour != parent[top]) {
                        // --- Cycle detection and cycle set creation start ---
                        unordered_set<int> cycle_set;
                        int cur = top;
                        cycle_set.insert(neighbour);
                        while (cur != neighbour) {
                            cycle_set.insert(cur);
                            cur = parent[cur];
                        }
                        // --- Cycle detection and cycle set creation end ---

                        // Find the last edge in the cycle in the input
                        for (int i = edges.size() - 1; i >= 0; --i) {
                            int first = edges[i][0];
                            int second = edges[i][1];
                            if (cycle_set.count(first) && cycle_set.count(second)) {
                                return {first, second};
                            }
                        }
                    }
                }
            }
        }

        return {}; // No cycles found, but that should be impossible for this problem
    }
};
