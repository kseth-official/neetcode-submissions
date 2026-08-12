class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> window;
        int l = 0, r = 0;
        int maxL = 0;
        
        while (r < s.size()) {
            if (window.count(s[r]) == 0) {
                window.insert(s[r]);
            } else {
                maxL = max(maxL, (int) window.size());

                while (true) {
                    if (s[l] == s[r])
                        break;
                    window.erase(s[l]);
                    l++;
                }

                l++;
            }
            
            r++;
        }

        return max(maxL, (int) window.size());
    }
};
