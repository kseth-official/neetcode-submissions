class Solution {
public:
    int countSubstrings(string s) {
        for (int i=0;i<s.size();i++) {
            for (int l=i, r=i;l>=0 && r < s.size();l--, r++) {
                if (s[l] != s[r])
                    break;
                count++;    
            }
        }

        for (int i=0;i<s.size();i++) {
            for (int l=i, r=i+1;l>=0 && r < s.size();l--, r++) {
                if (s[l] != s[r])
                    break;
                count++;
            }
        }

        return count;
    }
private:
    int count = 0;
};
