class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        // -1 2 6 8 10 -3 -7 -11
        // 2 -1 6 8 10 -3 -7 -11
        // 2 -1 6 -3 10 -3 -7 -11

        vector<int> pos;
        vector<int> neg;
        for (int i=0;i<nums.size();i++) {
            if (nums[i] > 0)
                pos.push_back(nums[i]);
            else
                neg.push_back(nums[i]);
        }      

        int j=0;
        int k=0;
        for (int i=0;i<nums.size();i++) {
            if ((i & 1) == 0) {
                nums[i] = pos[j];
                j++;
            } else {
                nums[i] = neg[k];
                k++;
            }
        }

        return nums;
    }
};