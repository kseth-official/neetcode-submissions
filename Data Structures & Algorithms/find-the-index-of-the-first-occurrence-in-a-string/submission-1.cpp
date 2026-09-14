class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();

        vector<int> lps(m, 0);

        // first member of lps is 0 since lps consitutes
        // longest prefix-suffix not including the whole string
        // for 1 character string, it must be 0, so we start with i == 1
        int prevLPS = 0, i=1;

        while (i < m) {
            if (needle[i] == needle[prevLPS]) {
                lps[i] = prevLPS+1;
                i++;
                prevLPS +=1;
            } else if (prevLPS != 0) {
                prevLPS = lps[prevLPS-1]; 
            } else {
                lps[i] = 0;
                i++;
            }
        }


        i = 0;
        int j =0;

        while (i < n) {
            if (haystack[i] == needle[j]) {
                i++;
                j++;
            } else {
                if (j != 0) {
                    j = lps[j-1];
                } else {
                    i++;
                }
            }

            if (j == m)
                return i - m;
        }

        return -1;
    }
};