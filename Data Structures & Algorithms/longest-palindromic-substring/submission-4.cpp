class Solution {
public:
    string longestPalindrome(string s) {
        string solution = "";

        // Look for all odd-length palindromes centred at i for i in 0..n-1
        for (int i=0;i<s.size();i++) {
            int j=i-1, k=i+1;
            for (j=i-1,k=i+1;j>=0 && k<s.size();j--,k++) {
                if (s[j] != s[k]) {
                    break;                                       
                }
            }
            // pointing to last valid positions
            const string& curr = s.substr(j+1, k-j-1);
            if (curr.size() > solution.size()) {
                solution = curr;
            }
        }

        // Look for all even-length palindromes centred at (i,i+1) for i in in 0..n-2
        for (int i=0;i<s.size()-1;i++) {
            if (s[i] != s[i+1])
                continue;

            int j=i-1, k=i+2;
            for (j=i-1,k=i+2;j>=0 && k<s.size();j--,k++) {
                if (s[j] != s[k]) {
                    break;                                       
                }
            }
            
            // pointing to last valid positions
            const string& curr = s.substr(j+1, k-j-1);
            if (curr.size() > solution.size()) {
                solution = curr;
            }
        }

        return solution;
    }
};
