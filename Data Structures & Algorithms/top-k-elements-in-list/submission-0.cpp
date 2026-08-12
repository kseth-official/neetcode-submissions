class Solution {
public:
    static bool sortByValuesDescending(const pair<int,int>& a, const pair<int,int>& b) {
        return a.second > b.second;
    }
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> umap;

        for (int i=0;i<nums.size();i++) umap[nums[i]]++;

        vector<pair<int,int>> map_vector(umap.begin(), umap.end());

        sort(map_vector.begin(), map_vector.end(), sortByValuesDescending);

        vector<int> solution; solution.reserve(k);

        for (int i=0;i<k;i++) solution.push_back(map_vector[i].first);

        return solution;
    }
};
