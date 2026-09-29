class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        vector<int> last = intervals[0];

        int count = 0;
        for (int i=1;i<intervals.size();i++) {
            int s1 = last[0];
            int e1 = last[1];
            int s2 = intervals[i][0];
            int e2 = intervals[i][1];

            if (e1 <= s2) {
                // non-overlapping -> skip
                last = intervals[i];
            } else {
                last[1] = min(e1, e2);
                count++;
            }
        }

        return count;
    }
};
