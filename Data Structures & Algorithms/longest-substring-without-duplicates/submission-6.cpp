class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, r = 0;

        unordered_set<char> window;
        int longest = 0;

        while (r < s.size()) {
            if (window.count(s[r])) {
                // invalidation condition
                window.erase(s[l]);
                l++;
                continue;
            } 
            window.insert(s[r]);
            longest = max(longest, r - l + 1);
            r++;
        }

        return longest;
    }
};
