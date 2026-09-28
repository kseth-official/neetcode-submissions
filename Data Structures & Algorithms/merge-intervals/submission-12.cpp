class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        int n = intervals.size();

        // Sort by start time of each interval O(nlogn)
        sort(intervals.begin(), intervals.end());

        res.push_back(intervals[0]);

        for (int i=1;i<n;i++) {
            int s1 = res.back()[0];
            int e1 = res.back()[1];
            int s2 = intervals[i][0];
            int e2 = intervals[i][1];
            
            if (res.empty() || e1 < s2) {
                res.push_back(intervals[i]);
                // i1 is before i2
            } else {
                // i1 overlaps with i2
                // modify i+1 to be the merged interval
                // push i+1 into solution
                // this is because merged interval i+1 will be used in next loop
                // for the next merge comparison
                res.back()[1] = max(e1, e2);
            }
        }
        
        return res;
    }
};