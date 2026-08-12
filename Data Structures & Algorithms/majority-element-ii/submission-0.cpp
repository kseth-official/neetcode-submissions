class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> count;
        unordered_set<int> solution;
        int threshold = nums.size() / 3;

        for (int i=0; i<nums.size();i++) {
            count[nums[i]]++;

            if (count[nums[i]] > threshold)
                solution.insert(nums[i]);
        }

        return vector<int>(solution.begin(), solution.end());
    }
};