class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int, vector<int>> pq(stones.begin(), stones.end());

        while (!pq.empty()) {
            if (pq.size() == 1)
                return pq.top();
            int x=pq.top();
            pq.pop();
            int y=pq.top();
            pq.pop();

            if (x==y)
                continue;
            
            pq.push(abs(x-y));
        }

        return 0;
    }
};
