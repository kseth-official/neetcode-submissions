class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int l=0;

        for (int r=0;r<nums.size();r++) {
            if (nums[r] != 0) {
                if (l != r) {
                    nums[l] = nums[r];
                    nums[r] = 0;
                }
                l++;
            }
        }
    }
};