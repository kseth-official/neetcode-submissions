class Solution {
public:
    bool validPalindrome(string s) {
        for (int i=0,j=s.size()-1;i<s.size()/2;i++,j--) {
            if (s[i] != s[j]) {
                string copy1 = s;
                string copy2 = s;
                string iRem = copy1.erase(i,1);
                string jRem = copy2.erase(j,1);
                bool iPal = isPalindrome(iRem);
                bool jPal = isPalindrome(jRem);
                if (!iPal && !jPal)
                    return false;
                else 
                    return true;
            }
        }
        return true;
    }

    bool isPalindrome(string s) {
        for (int i=0,j=s.size()-1;i<s.size()/2;i++,j--) {
            if (s[i] != s[j])
                return false;
        }
        return true;
    }
};