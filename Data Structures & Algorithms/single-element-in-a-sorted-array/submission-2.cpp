class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if (nums.size() == 1)
            return nums[0];

        int l = 0, r = nums.size()-1;

        while (l <= r) {
            int m = l + (r-l) / 2;

            int first;
            if (m > 0 && nums[m-1] == nums[m]) {
                first = m-1;
            } else if (m < nums.size() && nums[m] == nums[m+1]) {
                first = m;
            } else {
                // solution was found
                return nums[m];
            }

            if (first % 2 == 0) {
                // we are to th left
                l = m+1;
            } else {
                r = m-1;
                // we are to the right
            }
        }

        // we should not reach here
        return -1;
    }
};