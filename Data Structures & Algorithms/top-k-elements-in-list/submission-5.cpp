class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> fq;
        for (int i=0;i<nums.size();i++)
            fq[nums[i]]++;

        auto cmp = [](pair<int,int>& a, pair<int,int>& b) {
            return a.second < b.second;
        };         

        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)> pq;
        for (const auto& p: fq) {
            pq.push(p);
        }

        vector<int> result;
        for (int i=0;i<k;i++) {
            result.push_back(pq.top().first);
            pq.pop();
        }

        return result;
    }
};
