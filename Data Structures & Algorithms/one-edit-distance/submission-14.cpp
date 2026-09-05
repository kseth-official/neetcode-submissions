class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int n = s.size();
        int m = t.size();
        
        // must be 0 or 1 character apart and unequal strings
        if (abs(n - m) > 1 || s == t)
            return false;

        if (n == m && n == 1 && s != t)
            return true;
            
        if (n == m) {
            int k = 0;
            for (int i=0;i<n;) {
                if (s[i] != t[i]) {
                    k++;
                    if (k == 2)
                        return false;
                }
                i++;
            }
            return true;
        } 
        
        // 1 char apart
        if (n < m) {
            int k = 0;
            for (int i=0;i<n;) {
                if (s[i] != t[i+k]){
                    k++;
                    if (k >= 2)
                        return false;
                    continue;
                }
                i++;
            }
        } else {
            int k = 0;
            for (int i=0;i<m;) {
                if (t[i] != s[i+k]){
                    k++;
                    if (k >= 2)
                        return false;
                    continue;
                }
                i++;
            }
        }
     
        return true;
    }
};
