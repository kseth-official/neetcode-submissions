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
        helper(s, s.size());
        return count;
    }

    void helper(string&s, int j) {
        if (j == 0)
            return;

        for (int i=0;i<s.size();i++) {
            // take substrings of size j, but only it fits starting at index i, otherwise skip
            // 0 + 3 <= 3
            if (i + j <= s.size()) {
                string entry = s.substr(i, j);
                if (isPalindrome(entry))
                    count++;
            }
        }   
        helper(s, j-1);
    }

    bool isPalindrome(string& s) {
        for (int i=0,j=s.size()-1;i<s.size()/2;i++,j--) {
            if (s[i] != s[j])
                return false;
        }
        return true;
    }

private:
    int count = 0;
};
