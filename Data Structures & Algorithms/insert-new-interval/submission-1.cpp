class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        // t:  1 2 3 4 5 6
        // 1:  1   3
        // 2:        4   6
        // 3:    2    5
        // r:  1         6
        vector<vector<int>> res;
        for (int i=0;i<intervals.size();i++) {
            int a = newInterval[0];
            int b = newInterval[1];
            int x = intervals[i][0];
            int y = intervals[i][1];

            if (b < x) {
                res.push_back(newInterval);
                copy(intervals.begin() + i, intervals.end(), back_inserter(res));
                return res;
            } else if (y < a) {
                res.push_back(intervals[i]);
            } else {
                newInterval[0]=min(a, x);
                newInterval[1]=max(b,y);
            }
        }

        res.push_back(newInterval);

        return res;
    }
};