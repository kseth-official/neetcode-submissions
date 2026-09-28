class Solution {
public:
    int count = 0;
    unordered_set<string> tokens;

    int numDecodings(string s) {
        if (s[0] == '0')
            return 0;

        if (s.size() == 1) {
            return 1;
        }

        int n = s.size();
        
        for (int i=1;i<=26;i++) {
            tokens.insert(to_string(i));
        }

        vector<int> memo(n+1, -1);

        return bt(s, 0, n, memo);
        
        // T[s, i, n-(i-1)] = T[s, i, 1], if s.len == 1
        // T[s, i, n-(i-1)] = T[i, 1] + T[i+1,1] + T[i, 2], s.len == 2

    }

    int bt(string& s, int i, int n, vector<int>& memo) {
        if (i == n) {
            return 1;
        }

        string st = s.substr(i,1);

        if (st == "0")
            return 0;

        if (memo[i] != -1)
            return memo[i]; 
        
        int ways;
        if (tokens.count(st) > 0) {
            ways = bt(s, i+1, n, memo);
        }

        if (i+2<=n && tokens.count(s.substr(i,2)) > 0) {
            ways+=bt(s, i+2, n, memo);
        }

        memo[i] = ways;
        return ways;
    }
};
