class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res = nums.size(); // start with n because i in [0..n-1]
        for (int i=0;i<nums.size();i++) {
            // n ^ 0 ^ 1 ^ ... ^ n-1 ^ nums[0] ^ nums[1] ^ ... ^ nums[n-1]
            // one number is missing from nums. XOR inverse principle
            // cancels out all a ^ a = 0 so only the missing number is left
            res ^= i ^ nums[i];
        }
        return res;
    }
};
