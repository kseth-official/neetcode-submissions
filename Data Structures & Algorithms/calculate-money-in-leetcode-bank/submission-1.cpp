class Solution {
public:
    int totalMoney(int n) {
        /*
            7*(7+1)/2 + 8(8+1)/2-1(1+1)/2 + ... + k(k+1)/2-p(p+1)/2 
            Sum k=7:7+(n//7-1) [k(k+1)/2 - (k-7)(k-6)/2]

            [k*2+k-(k^2-6k-7k+42)]/2
            =14k-42
            =7k-21
            =7(k-3)
        */

        int d = n/7;
        int t=0;
        for (int i=7;i<=7+d-1;i++) {
            // t+= (i*(i+1)-(i-7)*(i-6))/2;
            t+=7*(i-3);
        }

        int x=d+1;
        int r=n%7;
        for (int i=0;i<r;i++) {
            t+=x+i;
        }

        return t;
    }
};
