class Solution {
public:
    int minOperations(string s) {
        int c1 = 0, c2 = 0;

        // 0 loop
        for (int i=0;i<s.size();i++) {
            if ((i & 1) == 0) {
                if (s[i] == '1')
                    c1++;
                else 
                    c2++;
            } else {
                if (s[i] == '0')
                    c1++;
                else
                    c2++;
            }
        }

        return min(c1, c2);
    }
};