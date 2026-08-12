class Solution {
public:
    vector<vector<string>> result;

    vector<vector<string>> partition(string s) {
        dfs(s,0,{});
        return result;
    }

    void dfs(string& s, int i, vector<string> partFB) {
        if (i == s.size()) {
            result.push_back(partFB);
            return;        
        }

        for (int j = i; j < s.size(); j++) {
            string subs = s.substr(i, j-i+1);
            if (isPalindrome(subs)) {
                partFB.push_back(subs);
                dfs(s,j+1,partFB);
                partFB.pop_back();
            }
        }
    }

    bool isPalindrome(string s) {
        for (int i = 0, j = s.size()-1; i < s.size() / 2; i++, j--) {
            if (s[i] != s[j])
                return false;
        }
        return true;
    }
};
