class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> fq(3, 0);

        for (const auto& n: nums) 
            fq[n]++;

        int j=0;
        for (int i=0;i<nums.size();i++) {
            while (fq[j]==0)
                j++;
            nums[i]=j;
            fq[j]--;
        }
    }
};