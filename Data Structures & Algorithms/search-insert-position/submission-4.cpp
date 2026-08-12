class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (target < nums.front())
            return 0;
        if (target > nums.back()) {
            return nums.size();
        }

        int l=0,r=nums.size()-1;

        int mid;
        while (l<=r) {
            mid = l + (r-l) / 2;

            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                l = mid+1;
            } else if (target < nums[mid]) {
                r = mid-1;
            }
        }

        return l;
    }
};