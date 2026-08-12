class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int solution = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            solution ^= nums[i];
        }

        return solution;
    }
};
