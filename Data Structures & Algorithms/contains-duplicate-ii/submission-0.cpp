class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> window;

        for (int i=0;i<k+1;i++) {
            if (window.count(nums[i]) > 0) {
                return true;
            }
            window.insert(nums[i]);
        }

        int i=0,j=k+1;
        while (j < nums.size()) {
            window.erase(nums[i]);

            if (window.count(nums[j]) > 0) {
                return true;
            }

            window.insert(nums[j]);
            i++;
            j++;
        }

        return false;
    }
};