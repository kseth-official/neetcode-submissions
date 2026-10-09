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
            // enforce canonical order so the current index can be chosen
            // again first
            dfs(nums, t-val, res, i);
            res.pop_back();
        }
    }
};
