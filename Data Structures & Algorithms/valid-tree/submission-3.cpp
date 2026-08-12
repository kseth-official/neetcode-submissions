class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        // A tree with n nodes must have exactly n-1 edges
        if (edges.size() != n - 1) return false;

        vector<vector<int>> adl(n);
        for (const auto& edge: edges) {
            adl[edge[0]].push_back(edge[1]);
            adl[edge[1]].push_back(edge[0]);
        }

        stack<int> s;
        
        unordered_set<int> visited;
        s.push(0);
        visited.insert(0);

        while (!s.empty()) {
            int top = s.top();
            s.pop();

            for (const auto& node: adl[top]) {
                // Found a cycle so not a tree
                if (visited.find(node) == visited.end()) {
                    s.push(node);
                    visited.insert(node);
                }
            }
        }

        return visited.size() == n;
    }
};
