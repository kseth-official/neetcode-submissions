class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> curr_subs;
        dfs(nums, 0, curr_subs, res, target);
        return res;
    }

    void dfs(const vector<int>& nums, int i, vector<int>& curr_subset, vector<vector<int>>& res, int target) {
        if (target == 0) {
            res.push_back(curr_subset);
            return;
        }

        if (i == nums.size() || target < 0) {
            return;
        }
        
        curr_subset.push_back(nums[i]);
        dfs(nums,i,curr_subset,res,target-nums[i]);

        curr_subset.pop_back();
        dfs(nums,i+1,curr_subset,res,target);
    }
};
