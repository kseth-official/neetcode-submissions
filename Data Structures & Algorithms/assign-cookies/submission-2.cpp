class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int i=0; // child index
        int j=0; // cookie index

        while (i<g.size() && j<s.size()) {
            if (s[j] >= g[i]) {
                // found a matching cookie
                i++;
            }

            // always move the cookie 
            j++;
        }

        return i;
    }
};