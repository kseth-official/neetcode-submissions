class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int result=0;
        // iterate i from 0...31
        for (int i=0;i<32;i++) {
            uint32_t bit = (n >> i) & 1;
            result+= (bit << (31-i));
        }
        return result; 
    }
};
