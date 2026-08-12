class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> w;
        int l = 0, r = 0;
        int longest_subs = 0;

        while (r < s.size()) {
            while (w.find(s[r]) != w.end()) {
                w.erase(s[l]);
                l++;
            }
            w.insert(s[r]);
            longest_subs = max(longest_subs, r - l + 1);
            r++;
        }

        return longest_subs;
    }
};
