class Solution {
public:
    struct PairHash {
        size_t operator()(const pair<string,string>& p) const noexcept {
            size_t h1 = hash<string>{}(p.first);
            size_t h2 = hash<string>{}(p.second);

            return h1 ^ (h2 << 1);
        }
    };
    
    int longestCommonSubsequence(string text1, string text2) {
        if (text1.size() < text2.size())
            return longestCommonSubsequence(text2,text1);

        // auto hash = [](const pair<string,string>& p) noexcept -> size_t {
        //     int h1 = hash<string>{}(p1);
        //     int h2 = hash<string>{}(p2);
// 
        //     return h1 ^ (h2 << 1);
        // };

        unordered_map<pair<string,string>, int, PairHash> memo;

        return dfs(text1,text2,0,0,memo);
    }

    int dfs(string& s1, string& s2, int i, int j, unordered_map<pair<string,string>,int,PairHash>& memo) {
        // both strings empty
        if (s1.empty() || s2.empty())
            return 0;
        
        // reached past end of either string
        if (i >= s1.size() || j >= s2.size())
            return 0;
        
        string s11 = s1.substr(i);
        string s22 = s2.substr(j);

        if (memo.count({s11, s22}) > 0) {
            return memo[{s11,s22}];
        }

        int res;
        if (s1[i] == s2[j])
            res = 1 + dfs(s1, s2, i+1,j+1,memo);
        else
            res = max(dfs(s1,s2,i,j+1,memo), dfs(s1,s2,i+1,j,memo));
        
        memo[{s11, s22}] = res;

        return res;
    }
};
