class Solution {
public:
    int countSubstrings(string s) {
        // find a way to list all the substrings efficiently, there's likely some caching
        // that can be done here for memoization (top-down) or order (bottom-up) that
        // can be used for DP. Investigate DP space optimization after
        // there's no 0 character substring
        
        // backtracking to list substrings?
        // abc
        // a b c ab bc abc
        
        // abc -> ab
        // ab -> a
        // 

        // abcd
        // abc bcd
        // ab bc bc cd
        // a b b c b c c d

        // substring palindromes in parent == sum of substring palindromes in children,
        // provided substring palindrome hasn't already been counted before

        // a = 1, b = 1, ab = 2, c = 1, bc = 1, d = 1, cd = 1, abc = 3, bcd = 1, abcd = 

        for (int i=0;i<s.size();i++) {
            for (int l=i, r=i;l>=0 && r < s.size();l--, r++) {
                const string& val = s.substr(l, r - l + 1);
                if (isPalindrome(val))
                    count++;
            }
        }

        for (int i=0;i<s.size();i++) {
            for (int l=i, r=i+1;l>=0 && r < s.size();l--, r++) {
                const string& val = s.substr(l, r - l + 1);
                if (isPalindrome(val))
                    count++;
            }
        }
        return count;
    }

    bool isPalindrome(const string& s) {
        for (int i=0,j=s.size()-1;i<s.size()/2;i++,j--) {
            if (s[i] != s[j])
                return false;
        }
        return true;
    }

private:
    int count = 0;
};
