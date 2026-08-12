class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        unordered_set<int> to_use(nums.begin(), nums.end());
        vector<int> curr_subs;
        dfs(res, curr_subs, to_use, nums.size());
        return res;
    }

    void dfs(vector<vector<int>>& res, vector<int>& curr_subs, unordered_set<int>& to_use, int n) {
        if (curr_subs.size() == n) {
            res.push_back(curr_subs);
            return;
        }

        vector<int> copy(to_use.begin(), to_use.end());

        for (const int& num: copy) {
            curr_subs.push_back(num);
            to_use.erase(num);
            dfs(res, curr_subs, to_use, n);
            to_use.insert(num);
            curr_subs.pop_back();
        }
    }
};