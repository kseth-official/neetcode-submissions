class Solution {
public:
    string decodeString(string s) {
        stack<string> ss;
        stack<int> cs;

        string cur = "";
        int count = 0;

        for (const auto& c: s) {
            if (isdigit(c)) {
                count = count*10 + (c - '0');
            } else if (c == '[') {
                ss.push(cur);
                cs.push(count);

                // reset cur and count
                cur.clear();
                count=0;
            } else if (c == ']') {  
                string inner = cur;
                cur = ss.top();
                ss.pop();

                int mult = cs.top();
                cs.pop();

                for (int i=0;i<mult;i++) {
                    cur += inner;
                }
            } else {
                cur += c;
            }
        }

        return cur;
    }
};