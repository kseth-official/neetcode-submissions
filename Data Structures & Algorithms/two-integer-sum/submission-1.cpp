class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
                unordered_map<int, unordered_set<int>> umap;

        for (int i = 0; i < nums.size(); i++) { 
            umap[nums[i]].insert(i);
        }
        
        for (int i = 0; i < nums.size(); i++) { 
            if (umap.find(target-nums[i]) != umap.end()) {
                for (const auto& index: umap[target-nums[i]]) {
                    if (index != i) {
                        return {i, index};
                    }
                }
            }
        }

        return vector<int>();
    }
};
