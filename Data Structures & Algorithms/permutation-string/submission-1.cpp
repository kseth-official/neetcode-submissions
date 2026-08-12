class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size())
            return false;

        int l = 0, r = s1.size() - 1;
        unordered_map<char,int> window;

        for (int i = 0; i < s1.size(); i++) {
            if (window.find(s2[i]) != window.end()) {
                window[s2[i]]++;
            } else {
                window[s2[i]] = 1;
            }
        }
        
        while (r < s2.size()) {
            auto window_copy = window;
            bool flag = true;
            for (const auto& ch: s1) {
                bool was_found = window_copy.find(ch) != window_copy.end();
                if (was_found && window_copy[ch] > 0) {
                    window_copy[ch]--;
                    continue;
                }
                flag = false;
                break;
            }

            if (flag) 
                return true;

            window[s2[l]]--;
            l++;
            r++;
            window[s2[r]]++;
        }

        return false;
    }
};