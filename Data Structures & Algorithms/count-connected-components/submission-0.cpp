class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        int count = 0;

    /*
        Construct adjacencly list representation of graph using edges
        Go through every node in adjacency list (node -> list of nodes is the contents of every member of the outer vector)
        and run dfs while marking each node that you visit as visited.
        If running dfs any time is able to start (found a node not already visited)
        count++
    */         

        vector<vector<int>> adj_list(n);

        for (const auto& edge : edges) {
            adj_list[edge[0]].push_back(edge[1]);
            adj_list[edge[1]].push_back(edge[0]);
        }

        unordered_set<int> visited;
        
        for (int i = 0; i < adj_list.size(); i++) {
            if (visited.count(i) == 0) {
                count++;

                stack<int> s;
                s.push(i);
                visited.insert(i);
                
                while (!s.empty()) {
                    int t = s.top();
                    s.pop();

                    for (const auto& neighbor: adj_list[t]) {
                        if (visited.count(neighbor) == 0) {
                            s.push(neighbor);
                            visited.insert(neighbor);
                        }
                    }
                }
            }
        }

        return count;
    }
};
