class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if (ransomNote.size() > magazine.size())
            return false;
            
        unordered_map<char,int> m;

        for (const auto& c: magazine) {
            m[c]++;
        }

        for (const auto& c: ransomNote) {
            m[c]--;
        }

        for (const auto& t: m) {
            if (t.second < 0)
                return false;
        }

        return true;
    }
};