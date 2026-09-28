class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;

        // Sort by start time of each interval O(nlogn)
        // ties are broken using equality. each interval has same length so this is natural
        sort(intervals.begin(), intervals.end());

        // this handles the single interval case naturally
        res.push_back(intervals[0]);

        for (int i=1;i<intervals.size();i++) {
            int s1 = res.back()[0];
            int e1 = res.back()[1];
            int s2 = intervals[i][0];
            int e2 = intervals[i][1];
            
            if (e1 < s2) {
                res.push_back(intervals[i]);
                // i1 is before i2
            } else {
                // i1 overlaps with i2
                res.back()[1] = max(e1, e2);
            }
        }
        
        return res;
    }
};