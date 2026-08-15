class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int start = nums[0];
        for (int i=1;i<nums.size();i++) {
            start ^= nums[i];
        }
        return start;
    }
};
