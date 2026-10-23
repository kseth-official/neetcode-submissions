class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> fq(26, 0);

        for (const auto& c: s) {
            fq[c-'a']++;
        }

        for (const auto& c: t) {
            fq[c-'a']--;
        }

        for (const auto& n: fq) {
            if (n != 0)
                return false;
        }

        return true;
    }
};
