class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        int last = intervals[0][1];

        int count = 0;
        for (int i=1;i<intervals.size();i++) {
            int e1 = last;
            int s2 = intervals[i][0];
            int e2 = intervals[i][1];

            if (e1 <= s2) {
                // non-overlapping -> skip
                last = intervals[i][1];
            } else {
                last = min(e1, e2);
                count++;
            }
        }

        return count;
    }
};
