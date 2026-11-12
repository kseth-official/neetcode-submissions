class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        vector<int> temp(nums.size());
        ms(nums,temp,0,nums.size()-1);
        return nums;
    }

    void ms(vector<int>& nums, vector<int>& temp, int l,int r) {
        if (l>=r)
            return;
        int m=l+(r-l)/2;
        ms(nums,temp,l,m);
        ms(nums,temp,m+1,r);
        merge(nums,temp,l,m,r);
    }

    void merge(vector<int>& nums, vector<int>& temp,int l,int m,int r) {
        int i=l,j=m+1,k=l;

        while (i<=m && j <=r) 
            temp[k++] = nums[i]<=nums[j] ? nums[i++] : nums[j++];
        while (i<=m)
            temp[k++]=nums[i++];
        while(j<=r)
            temp[k++]=nums[j++];
        
        int x=l;
        while (x <=r) {
            nums[x]=temp[x];
            x++;
        }
    }
};