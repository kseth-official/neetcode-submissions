class Solution {
public:
    int getSum(int a, int b) {
        // Use parity addition with bitwise and and left shifting
        // carry = (a & b) << 1
        // a = a ^ b
        // b = carry
        
        while (b != 0) {
            int carry = (a & b) << 1;
            a = a ^ b;
            b = carry;
        }

        return a;
    }
};
