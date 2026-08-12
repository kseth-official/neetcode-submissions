class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;

        unordered_map<char, int> umap;
        
        for (int i = 0; i < s.size(); i++)
            umap[s[i]]++;

        for (int i = 0; i < t.size(); i++)
            umap[t[i]]--;

        for (const auto& pair : umap) {
            if (pair.second != 0) {
                return false;
            }
        }

        return true;
    }
};
