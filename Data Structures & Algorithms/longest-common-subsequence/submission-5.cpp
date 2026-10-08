class Solution {
public:
    struct PairHash {
        size_t operator()(const pair<int,int>& p) const noexcept {
            size_t h1 = hash<int>{}(p.first);
            size_t h2 = hash<int>{}(p.second);

            return h1 ^ (h2 << 1);
        }
    };
    
    int longestCommonSubsequence(string text1, string text2) {
        if (text1.size() < text2.size())
            return longestCommonSubsequence(text2,text1);

        unordered_map<pair<int,int>, int, PairHash> memo;

        return dfs(text1,text2,0,0,memo);
    }

    int dfs(string& s1, string& s2, int i, int j, unordered_map<pair<int,int>,int,PairHash>& memo) {
        // reached past end of either string
        if (i >= s1.size() || j >= s2.size())
            return 0;
        
        if (auto it = memo.find({i, j}); it != memo.end()) {
            return it->second; 
        }

        int res;
        if (s1[i] == s2[j])
            res = 1 + dfs(s1, s2, i+1,j+1,memo);
        else
            res = max(dfs(s1,s2,i,j+1,memo), dfs(s1,s2,i+1,j,memo));
        
        memo[{i,j}] = res;

        return res;
    }
};
