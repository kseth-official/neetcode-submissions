class Solution {
public:
    int arrangeCoins(int n) {
        long a = n;
        return static_cast<int>(floor((-1 + sqrt(1+8*a)))/2);
    }
};