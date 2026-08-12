class Solution {
public:
    int findMin(vector<int> &nums) {
        int l = 0, r = nums.size()-1;

        int ret = nums[0];
        while (l <= r) {
            if (nums[l] < nums[r]) {
                ret = min(ret, nums[l]);
                break;
            }

            int m = l + (r-l)/2;
            ret = min(ret, nums[m]);

            if (nums[l] <= nums[m]) {
                // [2 3 4 5 6 1]
                l = m+1;
            } else if (nums[l] > nums[m]) {
                // [6 1 2 3 4 5]
                r = m-1;
            }
        }

        return ret;
    }    
};
