class Solution {
public:

    string encode(vector<string>& strs) {
        string res = "";
        for (const auto& s: strs) {
            res+=to_string(s.size()) + "#" + s;
        }
        return res;
    }

    vector<string> decode(string s) {
        vector<string> tokens;
        stringstream ss(s);
        char delimiter = '#';
        string token;

        string temp;
        while(getline(ss,temp,'#')) {
            int len = stoi(temp);

            string token(len, 't');
            ss.read(&token[0], len);

            tokens.push_back(token);
        }

        return tokens;
    }
};
