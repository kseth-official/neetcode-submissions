class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        long long sum = 0;
        priority_queue<int, vector<int>> pq(gifts.begin(), gifts.end());

        for (int i=0;i<k;i++) {
            int t = pq.top();
            pq.pop();
            pq.push(sqrt(floor(t)));
        }

        while (!pq.empty()) {
            sum+= pq.top();
            pq.pop();
        }

        return sum;
    }
};