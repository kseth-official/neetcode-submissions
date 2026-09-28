class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        /*
            001 1
            010 2
            011 3
            100 4
            101 5
            110 6
            111 7

            1010
            1100

            1000
        */

        int sln = left;
        for (int i=left;i<=right;i++) 
            sln &= i;
        return sln;
    }
};