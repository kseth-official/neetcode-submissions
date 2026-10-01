class Solution {
public:
    string decodeString(string st) {
        stack<char> s;
        string res = "";

        for (const auto& c: st) {
            if (c != ']') {
                s.push(c);
                continue;
            }
            string cur = "";
            while (!s.empty()) {
                char a = s.top();
                s.pop();
                if (a != '[')
                    cur += a;
                else 
                    break;
            }

            string mult = "";
            while (!s.empty()) {
                char a = s.top();
                if (isdigit(a)) {
                    mult+=a;
                    s.pop();
                } else 
                    break;
            }

            reverse(mult.begin(), mult.end());

            for (int i=0;i<stoi(mult);i++) {
                for (int j=static_cast<int>(cur.size())-1;j>=0;j--) {
                    s.push(cur[j]);
                }
            }
        }

        while (!s.empty()) {
            res+=s.top();
            s.pop();
        }

        reverse(res.begin(), res.end());

        return res;
    }
};