class Solution {
   public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        map<string, vector<string>> adj_list;

        for (const auto& ticket : tickets) {
            string from_i = ticket[0];
            string to_i = ticket[1];

            adj_list[from_i].push_back(to_i);
        }
        
        for (auto& [src, dest]: adj_list) {
            sort(dest.begin(), dest.end(), greater<string>());
        }
        
        vector<string> result;
        dfs(adj_list, result, "JFK");
        reverse(result.begin(), result.end());
        return result;
    }

    void dfs(map<string, vector<string>>& adj_list, vector<string>& result, string airport) {
        while (!adj_list[airport].empty()) {
            string next = adj_list[airport].back();
            adj_list[airport].pop_back();
            dfs(adj_list, result, next);
        }
        result.push_back(airport);
    }
};
