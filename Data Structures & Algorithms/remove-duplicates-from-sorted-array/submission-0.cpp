class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int lastUniqueIndex = 0;
        int i = 0, j = 0;

        // window keeps track of all equal elements, i = first member of equal elements, j = last member of equal elements
        // lastUniqueIndex is the index to fill in with the value of j once a new member is discovered, ex: 2, 2, 10 
        // 10 is added at index 1
        while (j < nums.size()) {
            if (nums[i] == nums[j]) {
                j++;
                continue;
            }
            lastUniqueIndex++;
            nums[lastUniqueIndex] = nums[j];
            i = j;
        }

        return lastUniqueIndex+1;
    }
};