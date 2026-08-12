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

        for (auto& kv: count) {
            kv.second = 0;    
        }

        unordered_set<int> result;
        for (const auto& num: nums) {
            if (count.count(num) > 0) {
                count[num]++;
            }

            if (count[num] > nums.size() / 3)
                result.insert(num);
        }


        return vector<int>(result.begin(), result.end());
    }
};