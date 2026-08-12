class Solution {
public:
    bool isHappy(int n) {
        vector<int> digits;
        unordered_set<int> seen;
        seen.insert(n);

        while (n != 1) {
            int copy = n;
            while (copy != 0) {
                digits.push_back(copy % 10);
                copy /=  10;
            }

            int sum = 0;
            for (const auto& digit: digits) {
                sum+=digit*digit;
            }
            if (seen.count(sum) > 0)
                return false;
            seen.insert(sum);
            n = sum;
            digits.clear();
        }
        
        return true;
    }
};
