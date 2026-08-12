class Solution {
public:
    bool isValid(string s) {
        stack<char> validator;

        for (const auto& ch: s) {
            if (isOpenBracket(ch)) {
                validator.push(ch);
                continue;
            }

            // Encountered a closing bracket without open brackets
            if (validator.empty() || (validator.top() != findCounterpart(ch)))
                return false;

            validator.pop();
        }

        if (!validator.empty())
            return false;

        return true;
    }

    char findCounterpart(char b) {
        if (b == '}') {
            return '{';
        } else if (b == ')') {
            return '(';
        } 

        return '[';
    }

    bool isOpenBracket(char b) {
        return b == '(' || b == '{' || b == '[';
    }
};
