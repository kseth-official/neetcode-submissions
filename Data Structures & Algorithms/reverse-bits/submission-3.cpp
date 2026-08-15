class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result=0;
        uint32_t TOTAL_BITS = sizeof(n) * 8;
        // iterate i from 0...31
        for (int i=0;i<TOTAL_BITS;i++) {
            uint32_t bit = (n >> i) & 1;
            result+= (bit << (TOTAL_BITS-1-i));
        }
        return result; 
    }
};
