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

        auto cmp = [](const pair<int,int>& a, const pair<int,int>& b) {
            if (a.first == b.first)
                return a.second < b.second;
            return a.first < b.first;
        };

        sort(time.begin(), time.end(), cmp);

        int c = 0, res = 0;
        for (const auto& p: time) {
            c+=p.second;
            res=max(res,c);
        }

        return res;
    }
};
