class Solution {
public:
    bool validPalindrome(string s) {
        for (int i=0,j=s.size()-1;i<s.size()/2;i++,j--) {
            if (s[i] != s[j]) {
                return isPalindrome(i+1,j,s) || isPalindrome(i,j-1,s);
            }
        }
        return true;
    }

    bool isPalindrome(int i, int j, string s) {
        for (;i<j;i++,j--) {
            if (s[i] != s[j])
                return false;
        }
        return true;
    }
};