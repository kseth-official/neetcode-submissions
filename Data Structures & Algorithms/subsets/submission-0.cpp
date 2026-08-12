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
            res.push_back(curr_subset);
            return;
        }

        curr_subset.push_back(nums[i]);
        dfs(nums, i+1,curr_subset,res);
        
        curr_subset.pop_back();
        dfs(nums, i+1,curr_subset,res);
    }
};
