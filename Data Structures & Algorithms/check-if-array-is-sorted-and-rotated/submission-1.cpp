class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int j;
        int sm = numeric_limits<int>::max(); 
        for (int i=0;i<nums.size();i++) {
            if (nums[i] < sm) {
                sm = nums[i];
                j = i;
            }
        }

        for (int k=0;k<n-1;k++) {
            if (nums[(j+k) % n] > nums[(j + 1 + k) % n])
                return false;
        }

        return true;
    }
};