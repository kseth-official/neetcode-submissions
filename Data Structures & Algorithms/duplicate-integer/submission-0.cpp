class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_map<int, int> umap;

        for (int i = 0; i < nums.size(); i++) {
            if (++umap[nums[i]] > 1) {
                return true;
            }
        }

        return false;
    }
};
