class Solution {
public:
    int bestClosingTime(string customers) {
        // use prefix penalty shop open
        // use postfix penatly shop closed
        // O(n) 
        int n = customers.size();

        vector<int> pr(n, 0);
        vector<int> po(n, 0);
        pr[0] = static_cast<int>(customers[0] == 'N');
        po[n-1] = static_cast<int>(customers[n-1] == 'Y');

        // Assuming open entire time
        for (int i=1;i<n;i++) {
            int pen = static_cast<int>(customers[i] == 'N');
            pr[i] = pr[i-1]+pen;
        }

        for (int i=n-2;i>=0;i--) {
            int pen = static_cast<int>(customers[i] == 'Y');
            po[i] = po[i+1]+pen;
        }

        int idx = 0;
        int mPen = numeric_limits<int>::max();
        // closed at index i
        for (int i=0;i<=n;i++) {
            int pen;
            if (i == 0)
                pen = po[0];
            else if (i == n)
                pen = pr[n-1];
            else {
                pen = pr[i-1]+po[i];
            }
            if (pen < mPen) {
                mPen = pen;
                idx = i;
            }
        }

        return idx;
    }
};