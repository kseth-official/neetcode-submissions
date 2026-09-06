class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        vector<int> result(heights.size(), 0);
        stack<int> mds;

        for (int i=heights.size()-1;i>=0;i--) {
            while (!mds.empty() && mds.top() < heights[i]) {
                mds.pop();
                result[i]++;
            }
            if (!mds.empty())
                result[i]++;
            mds.push(heights[i]);
        }

        return result;
    }
};