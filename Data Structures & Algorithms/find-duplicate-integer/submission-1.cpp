class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int i = 0;

        // Represents the value that we use as a next travel index in nums
        // When a duplicate is found, we return this value
        int prevNumI = -10001;
        while(true) {
            int val = nums[i];

            // We found the duplicate
            if (val < 0) {
                return -prevNumI;
            }

            prevNumI = -val;
            nums[i] = -val;
            i = val;
        }

        // 1 1
        // 1 5 3 2 5 4
    }
};
