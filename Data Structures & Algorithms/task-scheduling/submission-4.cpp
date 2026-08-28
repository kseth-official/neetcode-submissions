class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        auto cmp = [] (pair<int,int>& a, pair<int,int>& b) {
            return a.second < b.second;
        };

        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)> pq;

        unordered_map<char,int> fq;
        for (int i=0;i<tasks.size();i++) {
            fq[tasks[i]]++;
        }

        for (auto& p: fq) {
            pq.push(p);
        }

        queue<pair<pair<int,int>,int>> q;

        int t = 0;

        while (!pq.empty() || !q.empty()) {
            t++;
            if (!q.empty()) {
                auto top = q.front();

                if (top.second == t) {
                    q.pop();
                    pq.push(top.first);
                }
            }
            
            if (!pq.empty()) {
                auto top = pq.top();
                pq.pop();
                top.second--;

                if (top.second != 0) {
                    q.push({{top.first,top.second}, t+n+1});
                }
            }
        }

        return t;
    }
};
