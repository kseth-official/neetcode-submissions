class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        if (nums.size()<=1)
            return nums;

        int m = nums.size()/2;
        vector<int> a(nums.begin(),nums.begin()+m);
        vector<int> b(nums.begin()+m,nums.end());
        
        auto aa = sortArray(a);
        auto bb = sortArray(b);

        return merge(aa,bb);
    }

    vector<int> merge(vector<int>& a, vector<int>& b) {
        vector<int> res;

        int i=0,j=0;

        while (i < a.size() && j < b.size()) {
            if (a[i] < b[j]) {
                res.push_back(a[i]);
                i++;
            } else {
                res.push_back(b[j]);
                j++;
            }
        }

        while (i < a.size()) {
            res.push_back(a[i]);
            i++;
        }

        while (j < b.size()) {
            res.push_back(b[j]);
            j++;
        }

        return res;
    }
};