class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> num_set(nums.begin(), nums.end());

        int longest = 0;
        int current = 0;

        for (const auto& num: nums) {
            if (num_set.find(num-1) == num_set.end()) {
                current = 1;

                for (int i = 1; ; i++) {
                    if (num_set.find(num+i) == num_set.end()) {
                        break;
                    }
                    current++;
                }
    
                longest = max(current, longest);
            }
        }

        return longest;
    }
};
