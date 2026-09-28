class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if (ransomNote.size() > magazine.size())
            return false;
            
        vector<int> m(26);

        for (const auto& c: magazine) {
            m[c-'a']++;
        }

        for (const auto& c: ransomNote) {
            m[c-'a']--;
        }

        for (const auto& t: m) {
            if (t < 0)
                return false;
        }

        return true;
    }
};