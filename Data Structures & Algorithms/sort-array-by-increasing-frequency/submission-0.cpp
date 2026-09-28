class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int> f;

        for (int i=0;i<nums.size();i++) {
            f[nums[i]]++;
        }
        auto cmp = [&f](int a, int b) {
            if (f[a] == f[b])
                return a > b;
            return f[a] < f[b];
        };

        sort(nums.begin(), nums.end(), cmp);

        return nums;
    }
};