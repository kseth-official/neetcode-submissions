class Solution {
public:
    string minWindow(string s, string t) {
        string shortest = "";

        unordered_map<char,int> tm;
        for (const char& ch: t) {
            tm[ch]++;
        }

        int l = 0, r = 0;
        while (r < s.size()) {
            string window = s.substr(l, r-l+1);
            auto tm_copy = tm;

            // check if window ch exists in tmap_copy, and decrement count, erasing entry
            // if count reaches 0
            for (const auto& ch: window) {
                if (tm_copy.find(ch) != tm_copy.end()) {
                    int count = --tm_copy[ch];
                    if (count == 0) {
                        tm_copy.erase(ch);
                    }
                }
            }

            // if copy is empty, substring found
            if (tm_copy.empty()) {
                if (shortest == "") {
                    shortest = window;
                } else if (window.size() < shortest.size()) {
                    shortest = window;
                }

                l++;
            } else {
                r++;
            }
        }
 
        return shortest;
    }
};
