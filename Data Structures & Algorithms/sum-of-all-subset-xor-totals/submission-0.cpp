class Solution {
public:

    int XORTotal = 0;
    int subsetXORSum(vector<int>& nums) {
        backtrack(nums, 0, 0);
        return XORTotal;
    }

    // Use the pick/not pick pattern to generate subsets
    void backtrack(vector<int>& nums, int i, int curr_total) {
        if (i == nums.size()) {
            // we've reached a leaf node and know the total of the branch
            // so add it to our complete total
            XORTotal+=curr_total;
            return;
        }
        
        backtrack(nums, i+1, curr_total ^ nums[i]);
        backtrack(nums, i+1, curr_total);
    }

    
};