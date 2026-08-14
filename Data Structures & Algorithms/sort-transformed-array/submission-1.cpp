class Solution {
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        int l=0, r=nums.size()-1;
        vector<int> answer;
        if (a < 0) {
            while (l <= r) {
                int left = f(nums[l],a,b,c);
                int right = f(nums[r],a,b,c);
                if (left < right) {
                    answer.push_back(left);
                    l++;
                } else {
                    answer.push_back(right);
                    r--;
                }
            }
        } else {
            while (l <= r) {
                int left = f(nums[l],a,b,c);
                int right = f(nums[r],a,b,c);
                if (left > right) {
                    answer.push_back(left);
                    l++;
                } else {
                    answer.push_back(right);
                    r--;
                }
            }
            reverse(answer.begin(), answer.end());        
        }

        return answer;
    }

    int f(int x, int a, int b, int c) {
        return a * x * x + b * x +c;
    }
};
