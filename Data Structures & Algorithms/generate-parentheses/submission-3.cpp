class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> sols;
        bt(0, n*2, "", sols);
        return sols;
    }

    void bt(int i, int n, string curr, vector<string>& sols) {
        if (i == n) {
            if (isValid(curr)) {
                sols.push_back(curr);
            }
            // base case for adding a solution
            return;
        }

        curr.push_back('(');
        bt(i+1,n,curr, sols);
        curr.pop_back();
        curr.push_back(')');
        bt(i+1,n,curr, sols);
    }


    bool isValid(string& par) {
        stack<char> track;

        for (const auto& p: par) {
            if (p == '(') {
                track.push(p);
                continue;

            }

            if (p == ')') {
                if (track.empty())
                    return false;
                auto t = track.top();
                track.pop();
            }
        }

        if (!track.empty())
            return false;

        return true;
    }
};
