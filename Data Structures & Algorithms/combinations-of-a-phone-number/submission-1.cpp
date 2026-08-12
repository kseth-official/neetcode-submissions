class Solution {
public:
    vector<vector<char>> numberToLetters;
    vector<string> solution;

    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0)
            return solution;
        // construct vector of vector of number to letters
        // do backtracking over the digits provided, appending each new call with
        // a new letter from the corresponding index of digit we are currently looking at
        // if length of substring built till now == length of digits return
        // indexing into numberToLetters is offset by -2 from digit in digits
        numberToLetters = {
            {'a','b','c'},
            {'d','e','f'},
            {'g','h','i'},
            {'j','k','l'},
            {'m','n','o'},
            {'p','q','r','s'},
            {'t','u','v'},
            {'w','x','y','z'}
        };
        
        string init = "";
        dfs(0, init, digits);
        return solution;
    }

    void dfs(int i, string& current_subs, string& digits) {
        if (i == digits.size()) {
            solution.push_back(current_subs);
            return;
        }

        int digit = digits[i] - '0';
        vector<char>& letters = numberToLetters[digit-2];

        for (int j = 0; j < letters.size(); j++) {
            current_subs.push_back(letters[j]);
            dfs(i+1, current_subs, digits);
            current_subs.pop_back();            
        }
    }
};
