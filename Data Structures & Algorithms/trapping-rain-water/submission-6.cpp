class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        if (n <= 2)
            return 0;

        int res = 0;
        int mL = height[0];
        int mR = height[n-1];
        int l=1;
        int r=n-2;

        while (l <= r) {
            if (mL <= mR) {
                res += max(0, mL - height[l]);
                mL = max(mL, height[l]);
                l++;
            } else {
                res += max(0, mR-height[r]);
                mR = max(mR, height[r]);
                r--; 
            }
        } 

        return res;
    }
};
