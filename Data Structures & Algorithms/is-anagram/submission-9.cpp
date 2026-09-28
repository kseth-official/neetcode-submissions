class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> f;

        for (const auto& ch: s) {
            f[ch]++;
        }

        for (const auto& ch: t) {
            if (f.count(ch) == 0)
                return false;
            f[ch]--;
            if (f[ch] < 0)
                return false;
        }

        for (const auto& tup: f) {
            if (tup.second > 0)
                return false;
        }
        return true;
    }
};
