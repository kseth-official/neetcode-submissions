class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0)
            return static_cast<double>(1);
        double result = x;

        if (n > 0) {
            for (int i=0;i<n-1;i++) {
                result*=x;
            } 
        } else {
            for (int i=0;i<-(n-1);i++) {
                result*=1/x;
            } 
        }
        
        return result;
    }
};
