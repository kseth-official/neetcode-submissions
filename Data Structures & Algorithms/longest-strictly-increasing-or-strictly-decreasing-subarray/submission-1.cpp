class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        if (nums.size() == 1)
            return nums[0];

        int res = 1;
        int curr = 1;
        int l=0,r=1;

        while (r < nums.size()) {
            if (nums[l] < nums[r]) {
                curr++;
                res = max(res,curr);
            } else {
                curr=1;
            } 

            l++;
            r++;
        }

        curr = 1;
        l=0,r=1;
        while (r < nums.size()) {
            if (nums[l] > nums[r]) {
                curr++;
                res = max(res,curr);
            } else {
                curr=1;
            } 

            l++;
            r++;
        }

        return res;
    }
};