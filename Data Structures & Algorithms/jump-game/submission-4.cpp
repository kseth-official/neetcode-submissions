class Solution {
public:
    bool canJump(vector<int>& nums) {
        /*
            Starting from the beginning, jump to the step with the maximum future jump length.
            If there is a path to the end, you will reach it.
            If there is no path, the maximum future jump length will equal 0, meaning, you
            can't move forward from here.

            Solved Condition: position == nums.size() - 1
            Termination Condition: max future jump length == 0

            The answer is actually simpler if you start from the end.
        */

        int goal = nums.size()-1;

        for (int i = nums.size()-2;i>=0;i--) {
            if (i + nums[i] >= goal) {
                goal = i;
            }
        }

        return goal == 0;
    }
};
