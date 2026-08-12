class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> curr_subset;
        dfs(nums, 0, curr_subset, res);
        return res;
    }

    void dfs(const vector<int>& nums, int i, vector<int>& curr_subset, vector<vector<int>>& res) {
        if (i == nums.size()) {
            // in preorder fashion, if i is past last index in nums, it means we've 
            // reached the leaf of our decision tree choosing to include and not include at each node
            // the new element encountered at level i
            // T: O(n*2^n)
            // S: Height of Tree = O(n)
            res.push_back(curr_subset);
            return;
        }
        
        // choose to include nums[i]
        curr_subset.push_back(nums[i]);
        dfs(nums, i+1,curr_subset,res);
        
        // choose to not include nums[i]
        curr_subset.pop_back();
        dfs(nums, i+1,curr_subset,res);
    }
};
