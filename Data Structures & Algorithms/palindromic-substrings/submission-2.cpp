class Solution {
public:
    int countSubstrings(string s) {
        int solution=0;

        // Look for all odd-length palindromes centred at i for i in 0..n-1
        for (int i=0;i<s.size();i++) {
            solution++;
            for (int j=i-1,k=i+1;j>=0 && k<s.size();j--,k++) {
                if (s[j] != s[k]) {
                    break;                                       
                }
                solution++;
            }
        }

        // Look for all even-length palindromes centred at (i,i+1) for i in in 0..n-2
        for (int i=0;i<s.size()-1;i++) {
            if (s[i] != s[i+1])
                continue;

            solution++;
            for (int j=i-1,k=i+2;j>=0 && k<s.size();j--,k++) {
                if (s[j] != s[k]) {
                    break;                                       
                }
                solution++;
            }
        }

        return solution;
    }
};
