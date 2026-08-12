class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> umap;

        for (int i = 0; i < strs.size(); i++) {
            string current_key = strs[i];
            sort(current_key.begin(), current_key.end());
            umap[current_key].push_back(strs[i]);
        }

        vector<vector<string>> solution;
        for (const auto& pair: umap) {
            solution.push_back(pair.second);
        }

        return solution;
    }
};
