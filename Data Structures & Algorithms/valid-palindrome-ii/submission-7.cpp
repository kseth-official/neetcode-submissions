class Solution {
public:
    bool validPalindrome(string s) {
        int l=0,r=s.size()-1;

        while (l<=r) {
            if (s[l]!=s[r])
                return isP(s, l+1, r) || isP(s, l, r-1);

            l++;
            r--;
        }  

        return true;
    }

    bool isP(string& s, int i, int j) {
        while (i <= j) {
            if (s[i] != s[j])
                return false;

            i++;
            j--;
        }
        return true;
    }
};