class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int l=0,r=0;

        while (r < nums.size()) {
            if (nums[r] != 0) {
                if (l != r) {
                    nums[l] = nums[r];
                    nums[r] = 0;
                }
                l++;
            }
            r++;
        }
    }
};