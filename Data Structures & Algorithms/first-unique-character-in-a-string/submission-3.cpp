class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,pair<int,int>> m;

        for (int i=0;i<s.size();i++) {
            auto& [c, k] = m[s[i]]; 
            c++;
            if (k == 0)
                k=i;
        }

        int res = numeric_limits<int>::max();
        for (const auto& t: m) {
            if (t.second.first == 1)
                res = min(res,t.second.second);
        }

        return res == numeric_limits<int>::max() ? -1 : res;
    }
};