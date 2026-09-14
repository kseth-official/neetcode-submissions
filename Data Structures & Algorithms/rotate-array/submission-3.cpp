class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if (k % n == 0)
            return;
        k %= n;
        /*
            12345678 k=0
            81234567 k=1
            78123456 k=2
            67812345 k=3
            56781234 k=4
            45678123 k=5
            34567812 k=6
            23456781 k=7
        */

        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.end() - (n-k));
        reverse(nums.begin() + k, nums.end());
    }
};