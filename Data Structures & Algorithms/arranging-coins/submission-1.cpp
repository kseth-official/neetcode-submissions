class Solution {
public:
    int arrangeCoins(int n) {
        /*
            k*(k+1)/2 <= n
            k^2 + k <= 2n
            k^2 + k - 2n <= 0

            (-1 +- sqrt((1+8n)))/2


            ==
            
        */
        long a = n;

        return static_cast<int>(floor((-1 + sqrt(1+8*a)))/2);



    }
};