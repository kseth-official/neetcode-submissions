class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0)
            return 0;

        if (s.size() == 1)
            return 1;
        
        unordered_set<char> window;
        int l = 0, r = 0;
        int maxL = 0;
        
        while (r < s.size()) {
            if (window.count(s[r]) == 0) {
                window.insert(s[r]);
            } else {
                int window_size = window.size();
                maxL = max(maxL, window_size);

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
