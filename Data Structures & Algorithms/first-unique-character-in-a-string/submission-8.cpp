class Solution {
public:
    int firstUniqChar(string s) {
        vector<pair<int,int>> m(26, {0, -1});

        for (int i=0;i<s.size();i++) {
            auto& [c, k] = m[s[i]-'a']; 
            c++;
            if (k == -1)
                k=i;
        }

        int res = numeric_limits<int>::max();
        for (const auto& [c, k] : m) {
            if (c == 1)
                res = min(res,k);
        }

        return res == numeric_limits<int>::max() ? -1 : res;
    }
};