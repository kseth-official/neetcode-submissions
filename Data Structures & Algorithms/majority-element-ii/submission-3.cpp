class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> count;

        for (const auto& num: nums) {
            count[num]++;

            if (count.size() > 2) {
                unordered_map<int,int> new_count;

                for (const auto& kv: count) {
                    if (kv.second > 1)
                        new_count[kv.first] = kv.second - 1;
                }

                count = new_count;
            }
        }

        vector<int> res;
        for (auto& entry : count) {
            int frequency = 0;
            for (int num : nums) {
                if (num == entry.first) frequency++;
            }
            if (frequency > nums.size() / 3) {
                res.push_back(entry.first);
            }
        }

        return res;
    }
};