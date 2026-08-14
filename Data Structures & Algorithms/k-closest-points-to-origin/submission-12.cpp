class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto cmp = [this](pair<int,int>& a, pair<int,int>& b) {
            return dist(a.first, a.second, 0, 0) < dist(b.first, b.second, 0, 0);
        };
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)> closest(cmp);

        for (const auto& point: points) {
            closest.push({point[0], point[1]});
            if (closest.size() > k)
                closest.pop();
        }

        vector<vector<int>> answer;
        for (int i=0;i<k;i++) {
            auto max = closest.top();            
            closest.pop();
            answer.push_back({max.first, max.second});
        }

        return answer;
    }

    int dist(int x1, int y1, int x2, int y2) {
        return (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
    }
};
