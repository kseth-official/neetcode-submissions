class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        bool appendOne = true;
        int carry = 1;
        for (int i=digits.size()-1; i>=0;i--) {
            int val = digits[i];
            if (val + 1 < 10) {
                digits[i]+=carry;
                appendOne = false;
                break;
            }
            digits[i]=0;
            carry=1;
        }
        if (appendOne) {
            digits.push_back(1);
            reverse(digits.begin(), digits.end());
        }
            
        return digits;
    }
};
