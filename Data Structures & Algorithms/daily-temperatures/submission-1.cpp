class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>> pair_stack;
        vector<int> soln(temperatures.size(), 0);

        for (int i = 0; i < temperatures.size(); i++) {
            int curr_temp = temperatures[i];

            if (!pair_stack.empty() && curr_temp > pair_stack.top().first) {
                while (!pair_stack.empty() && curr_temp > pair_stack.top().first) {
                    auto top = pair_stack.top();
                    soln[top.second] = i - top.second;
                    pair_stack.pop();
                }
            }

            pair_stack.push({curr_temp, i});
        }

        return soln;
    }
};
