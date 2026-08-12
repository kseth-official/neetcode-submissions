#include <numeric>
#include <algorithm>

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefix_product;
        vector<int> postfix_product;
        prefix_product.reserve(nums.size());
        postfix_product.reserve(nums.size());

        prefix_product[0] = nums[0];
        postfix_product[nums.size()-1] = nums[nums.size()-1];
        
        for (int i=1, j = nums.size() - 1 - 1; i < nums.size(); i++, j--) {
            prefix_product[i] = prefix_product[i-1] * nums[i];
            postfix_product[j] = nums[j] * postfix_product[j+1];
        }

        vector<int> result(nums.size());
        result[0] = postfix_product[1];
        result[nums.size()-1] = prefix_product[nums.size()-1-1];

        for (int i = 1; i < nums.size()-1; i++) {
            result[i] = prefix_product[i-1] * postfix_product[i+1];
        }

        return result;
    }
};
