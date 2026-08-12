class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        /*
            Use DFS and find every member of a cycle.
            Any edge from the cycle can be removed, and we will have an
            Undirected Acyclic Graph.

            Return the edge in the cycle latest in edges

            Doing this recursively seems to make sense.
        */
        int n = edges.size();
        vector<vector<int>> adj_list(n+1);
        for (int i=0;i<edges.size();i++) {
            adj_list[edges[i][0]].push_back(edges[i][1]);
            adj_list[edges[i][1]].push_back(edges[i][0]);
        }   

        stack<int> s;
        vector<bool> visited(n+1, false);
        vector<int> parent(n+1,-1);
        s.push(edges[0][0]);

        while (!s.empty()) {
            int top = s.top();
            s.pop();

            if (!visited[top]) {
                visited[top]=true;
                for (const auto& neighbour: adj_list[top]) {
                    if (!visited[neighbour]) {
                        parent[neighbour] = top;
                        s.push(neighbour);
                    } else if (neighbour != parent[top]) {
                        unordered_set<int> cycle_set;
                        int cur = top;
                        cycle_set.insert(neighbour);
                        while (cur != neighbour) {
                            cycle_set.insert(cur);
                            cur = parent[cur];
                        }
                        
                        for (int i=edges.size()-1;i>=0;i--) {
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

        return {}; // no cycles found, but that should be impossible for this problem
    }
};
