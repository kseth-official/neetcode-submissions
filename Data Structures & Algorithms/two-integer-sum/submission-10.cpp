class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m;

        for (int i=0;i<nums.size();i++) {
            m[nums[i]] = i;
        }
        vector<int> sol;

        for (int i=0;i<nums.size();i++) {
            if (m.count(target-nums[i]) > 0) {
                int j = m[target-nums[i]];
                if (i!=j) {
                    sol = {min(i,j), max(i,j)};
                    break;
                }
            }       
        }

        return sol;
    }
};
