class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<int,int> c;
        for (int i=0;i<s.size();i++) {
            c[s[i]]++;
        }
        int sol = 0;
        bool hasOdd = false;
        for (const auto& tup: c) {
            sol += ((tup.second / 2) * 2);
            if (tup.second % 2 == 1)
                hasOdd = true;
        }

        return hasOdd ? ++sol : sol;
    }
};