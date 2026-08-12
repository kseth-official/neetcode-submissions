class Solution {
public:
    bool isValid(string s) {
        stack<char> validator;
        unordered_map<char, char> parens = {
            {')','('},
            {'}','{'},
            {']','['}
        };

        for (const auto& ch: s) {
            if (parens.find(ch) == parens.end()) {
                validator.push(ch);
                continue;
            }

            if (validator.empty() || (validator.top() != parens[ch]))
                return false;

            validator.pop();
        }

        if (!validator.empty())
            return false;

        return true;
    }
};
