class Solution {
public:
    vector<vector<int>> f;

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> res; 
        dfs(nums, target, res, 0);
        return f;
    }

    void dfs(vector<int>& nums, int t, vector<int>& res, int s) {
        if (t == 0) {
            f.push_back(res);
            return;
        }

        for (int i=s;i<nums.size();i++)  {
            int val = nums[i];
            if (t - val < 0)
                continue;
            res.push_back(val);
            // enforce canonical order so the current index is always 
            // chosen again first
            // This allows something like
            // 1 1 1 
            // 1 1 2
            // 1 2 1
            // 1 2 2
            // 2 1 1
            // 2 1 2
            // 2 2 1
            // 2 2 2
            // assuming nums = [1,2], where some iterations
            // would be stopped entirely if the sum goes above target
            dfs(nums, t-val, res, i);
            res.pop_back();
        }
    }
};
