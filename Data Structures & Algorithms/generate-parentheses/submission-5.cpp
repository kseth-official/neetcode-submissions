class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> sols;
        bt(0,0, n, "", sols);
        return sols;
    }

    void bt(int openCount, int closedCount, int n, string curr, vector<string>& sols) {
        if (openCount == n && closedCount ==n) {
            sols.push_back(curr);
            return;
        }

        if (openCount < n) {
            curr.push_back('(');
            bt(openCount+1, closedCount,n, curr, sols);
            curr.pop_back();
        }
        if (closedCount < openCount) {
            curr.push_back(')');
            bt(openCount, closedCount+1,n, curr, sols);
            curr.pop_back();
        }
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
