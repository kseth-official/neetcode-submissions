/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<pair<int,int>> time;

        for (const auto& i: intervals) {
            time.push_back({i.start, 1});
            time.push_back({i.end, -1});
        }

        sort(time.begin(), time.end());

        int c = 0, res = 0;
        for (const auto& p: time) {
            c+=p.second;
            res=max(res,c);
        }

        return res;
    }
};
