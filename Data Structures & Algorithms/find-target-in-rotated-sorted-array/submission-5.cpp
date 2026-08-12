class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1;

        while (l <= r) {
            if (nums[l] == target) {
                return l;
            }

            if (nums[r] == target) {
                return r;
            }
            
            int m = l + (r-l)/2;

            if (nums[m] == target) {
                return m;
            }

            if (target < nums[m]) {
                if (nums[m] < nums[l]) {
                    r = m-1;
                } else {
                    l = m+1;
                }
            } else {
                if (nums[m] < nums[l]) {
                    r = m-1;
                } else {
                    l = m+1;
                }
            }
        }

        return -1;
    }
};
