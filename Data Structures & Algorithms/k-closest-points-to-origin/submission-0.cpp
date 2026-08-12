class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto cmp = [](pair<int,int> left, pair<int,int> right) {
            // comparator for a kind of minHeap, prioritizing points with a smaller 2 norm from the origin
            return sqrt(pow(left.first,2) + pow(left.second,2)) > sqrt(pow(right.first,2) + pow(right.second,2));
        };

        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)> pq(cmp);

        for (const auto& point: points) {
            pair<int,int> new_point = {point[0], point[1]};
            pq.push(new_point);
        }

        vector<vector<int>> solution;
        for (int i=0;i<k;i++) {
            auto tup = pq.top();
            pq.pop();
            vector<int> point = {tup.first, tup.second};
            solution.push_back(point);
        }

        return solution;   
    }
};