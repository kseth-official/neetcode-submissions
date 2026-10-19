class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        bool x = false, y = false, z = false;
        int t1 = target[0];
        int t2 = target[1];
        int t3 = target[2];

        for (const auto& t: triplets) {
            int a=t[0];
            int b=t[1];
            int c=t[2];

            if (a == t1 && b <= t2 && c <= t3) {
                x = true;
            }

            if (a <= t1 && b == t2 && c <= t3) {
                y = true;
            }

            if (a <= t1 && b <= t2 && c == t3) {
                z = true;
            }

            if (x && y && z)
                return true;
        }

        return x && y && z; 
    }
};
