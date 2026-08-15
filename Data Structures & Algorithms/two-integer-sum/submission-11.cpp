class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m;
        vector<int> sol;

        for (int i=0;i<nums.size();i++) {
            if (m.count(target-nums[i]) > 0) {
                int j = m[target-nums[i]];
                sol = {j, i};
                break;
            }
            m[nums[i]]=i;       
        }

        return sol;
    }
};
