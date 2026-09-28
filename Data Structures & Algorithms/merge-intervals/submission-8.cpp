class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() == 1)
            return intervals;

        vector<vector<int>> res;
        int n = intervals.size();

        auto cmp = [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        };

        // Sort by start time of each interval O(nlogn)
        sort(intervals.begin(), intervals.end(), cmp);

        for (int i=0;i<n-1;i++) {
            int s1 = intervals[i][0];
            int e1 = intervals[i][1];
            int s2 = intervals[i+1][0];
            int e2 = intervals[i+1][1];
            
            if (e1 < s2) {
                res.push_back(intervals[i]);
                // i1 is before i2
            } else {
                // i1 overlaps with i2
                // modify i+1 to be the merged interval
                // push i+1 into solution
                // this is because merged interval i+1 will be used in next loop
                // for the next merge comparison
                intervals[i+1][0] = min(s1,s2);
                intervals[i+1][1] = max(e1,e2);
            }
        }

        // Handle n-1 case separately since we know there's at least 2 elements
        res.push_back(intervals[n - 1]);
        
        return res;
    }
};