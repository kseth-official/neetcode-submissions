class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int l=0,r=0;

        while (l < nums.size() && nums[l] != 0) {
            l++;
            r++;
        }

        while (r < nums.size()) {
            if (nums[r] != 0) {
                nums[l] = nums[r];
                nums[r] = 0;
                l++;
            }
            r++;
        }
    }
};