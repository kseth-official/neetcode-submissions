#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // If s1 is longer than s2, no permutation can exist
        if (s1.size() > s2.size())
            return false;

        unordered_map<char, int> s1m;
        unordered_map<char, int> s2m;

        // Count characters in s1
        for (const char& c : s1) {
            s1m[c]++;
        }

        // Build initial window in s2
        for (int i = 0; i < s1.size(); i++) {
            s2m[s2[i]]++;
        }

        // Check the initial window
        if (s1m == s2m) {
            return true;
        }

        // Sliding window over s2
        for (int r = s1.size(); r < s2.size(); r++) {
            // Add the next character to the window
            s2m[s2[r]]++;

            // Remove the leftmost character from the window
            char leftChar = s2[r - s1.size()];
            s2m[leftChar]--;
            if (s2m[leftChar] == 0) {
                s2m.erase(leftChar);
            }

            // Check if current window matches
            if (s1m == s2m) {
                return true;
            }
        }

        return false;
    }
};
