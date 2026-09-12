class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() == 1 || height.size() == 2)
            return 0;
        /*
            i, j

            min(h[i],h[j])*(j-i-1)
        */

        int mL = height[0];
        int mR = height[height.size()-1];
        int l = 1, r = height.size()-2; 
        int res = 0;

        while (l <= r) {
            if (mR <= mL) {
                res += max(0, mR - height[r]);

                mR = max(mR, height[r]);
                r--;
            } else {
                res += max(0, mL - height[l]);

                mL = max(mL, height[l]);
                l++;
            }
        }

        return res;
    }
};
