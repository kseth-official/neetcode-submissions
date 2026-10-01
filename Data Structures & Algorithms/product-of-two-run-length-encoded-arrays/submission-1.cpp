class Solution {
public:
    vector<vector<int>> findRLEArray(vector<vector<int>>& encoded1, vector<vector<int>>& encoded2) {
        vector<int> nums1, nums2;

        for (const auto& v: encoded1) {
            for (int i=0;i<v[1];i++) {
                nums1.push_back(v[0]);
            }
        }

        for (const auto& v: encoded2) {
            for (int i=0;i<v[1];i++) {
                nums2.push_back(v[0]);
            }
        }

        vector<int> prod(nums1.size(), 1);
        vector<vector<int>> res;

        for (int i=0;i<nums1.size();i++) {
            prod[i] = nums1[i]*nums2[i];

            if (res.empty() || res.back()[0] != prod[i]) {
                res.push_back({prod[i], 1});
            } else if (res.back()[0] == prod[i]) {
                res.back()[1]++;
            }
        }
        
        return res;
    }
};
