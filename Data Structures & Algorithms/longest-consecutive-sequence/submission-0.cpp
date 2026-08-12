class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> num_set(nums.begin(), nums.end());

        int longestSequenceLength = 0;
        int currentSequenceLength = 0;
        for (const auto& num: nums) {
            if (num_set.find(num-1) == num_set.end()) {
                currentSequenceLength = 1;

                for (int i = 1; ; i++) {
                    if (num_set.find(num+i) == num_set.end()) {
                        break;
                    }
                    currentSequenceLength++;
                }
    
                if (currentSequenceLength > longestSequenceLength) {
                    longestSequenceLength = currentSequenceLength;
                }
            }
            // if num set does not contain num - 1, then num is the start of a sequence
            // take num and keep incrementing by 1 starting at num and check if incremented num exists in set
            // if it exists, increment currentSequenceLength
            // if currentSequenceLength > longestSequenceLength
            // longestSequenceLength = currentSequenceLength
        }

        return longestSequenceLength;
    }
};
