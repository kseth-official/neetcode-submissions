class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto cmp = [this](const vector<int>& a, const vector<int>& b) {
            return distance(a, {0,0}) > distance(b, {0,0});
        };

        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq(cmp, points);

        vector<vector<int>> result;
        for (int i=0;i<k;i++) {
            result.push_back(pq.top());
            pq.pop();
        }

        return result;
    }

    double distance(const vector<int>& a, const vector<int>& b) {
        return sqrt(pow(a[0] - b[0], 2) + pow(a[1] - b[1], 2));
    }
};
