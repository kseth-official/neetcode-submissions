class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> solution;
        for (int i = 0; i < temperatures.size()-1;i++) {
            bool flag = false;
            for (int j = i + 1; j < temperatures.size();j++) {
                if (temperatures[i] < temperatures[j]) {
                    solution.push_back(j-i);
                    flag = true;
                    break;
                }
            }

            if (!flag) {
                solution.push_back(0);
            }
        }

        solution.push_back(0);

        return solution;
    }
};
