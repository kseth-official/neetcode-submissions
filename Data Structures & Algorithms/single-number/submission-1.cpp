class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int solution = 0;

        for (const auto& num: nums) {
            solution ^= num;
        }

        return solution;
    }
};
