class Solution {
public:
    bool isHappy(int n) {
        int slow = n, fast = sumOfSquaresDigits(n);

        while (fast != slow) {
            fast = sumOfSquaresDigits(fast);
            fast = sumOfSquaresDigits(fast);
            slow = sumOfSquaresDigits(slow);
        }

        return fast == 1;
    }

    int sumOfSquaresDigits(int n) {
        int sum = 0;
        while (n!=0) {
            sum += (n%10) * (n%10);
            n/=10;
        }
        return sum;
    }
};

