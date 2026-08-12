class Solution {
public:
    static bool sortByValuesDescending(const pair<int,int>& a, const pair<int,int>& b) {
        return a.second > b.second;
    }
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> umap;

        for (int i=0;i<nums.size();i++) 
            umap[nums[i]]++;

        vector<vector<int>> fbuckets(nums.size() + 1);

        for (const auto& pair : umap)
            fbuckets[pair.second].push_back(pair.first);
        
        vector<int> solution;
        solution.reserve(k);

        for (int i=fbuckets.size()-1;i>=0;i--) {
            if (!fbuckets[i].empty()) {
                for (int j=0;j<fbuckets[i].size();j++) {
                    solution.push_back(fbuckets[i][j]);
                    if (solution.size() == k)
                        return solution;
                }
            }
        }

        return solution;
    }
};
