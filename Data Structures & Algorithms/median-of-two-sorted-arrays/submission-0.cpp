class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // 1 2 3 4 5
        // 6 7 8 9 10
        if (nums1.size() > nums2.size())
            return findMedianSortedArrays(nums2,nums1);
        
        int total = nums1.size() + nums2.size();
        int half = (total+1) / 2;

        int l=0,r=nums1.size();

        while (l<=r) {
            int i = l + (r-l)/2;
            int j = half-i;
            int Al = i > 0 ? nums1[i-1] : numeric_limits<int>::min(); 
            int Ar = i < nums1.size() ? nums1[i] : numeric_limits<int>::max();
            int Bl = j > 0 ? nums2[j-1] : numeric_limits<int>::min();
            int Br = j < nums2.size() ? nums2[j] : numeric_limits<int>::max();

            if (Al <= Br && Bl <= Ar) {
                if ((total & 1) != 0)
                    return max(Al, Bl);
                else 
                    return static_cast<double>((max(Al, Bl) + min(Ar, Br))) / 2;
            } else if (Al > Br) {
                r=i-1;
            } else {
                l=i+1;
            }
        }

        return -1;
    }
};