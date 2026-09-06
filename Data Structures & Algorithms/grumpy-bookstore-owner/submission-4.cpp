class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int t = customers.size();
        int res = 0;
        for (int i=0;i<t;i++) {
            res += customers[i]*(!grumpy[i]);
        }


        int l=0, r=minutes-1;
        for (int i=0;i<=r;i++) {
            // not grumpy for initial window
            if (grumpy[i] == 1)
                res += customers[i];
        }
        int m = res;

        while (r < t-1) {
            res -= customers[l]*(grumpy[l]);
            l++;
            r++;
            res+= customers[r]*(grumpy[r]);
            m = max(res,m);
        }

        m = max(res,m);

        return m;
    }
};