class Solution {
public:
    bool isPalindrome(string s) {
        string copy = "";
        for (const char& ch: s) {
            if (isalnum(ch)) {
                copy += tolower(ch);
            }
        }

        for (int i = 0, j = copy.size()-1; i < copy.size(); i++, j--) {
            if (copy[i] != copy[j])
                return false;
        }

        return true;
    }
};
