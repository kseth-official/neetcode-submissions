class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        // validate abbreviation for form by splitting it into tokens
        int j = abbr.size()-1;
        int curr = 0;
        for (int i=word.size()-1;i>=0;i--) {
            auto& w = word[i];

            // see if we're blocking for a number
            if (curr > 0) {
                curr--;
                continue;
            }

            if (j < 0)
                return false;
            auto& a = abbr[j];

            if (w == a) {
                j--;
                continue;
            }

            // return false if abbr is a char and it doesn't match with word
            if (!isdigit(a))
                return false;

            // is digit... parse it and update j, we go backwards so we don't
            // have to calculate the number's length

            int exp = 1;
            int val;
            while (j >= 0 && isdigit(abbr[j])) {
                val = abbr[j] - '0';
                curr += val * exp;
                exp*=10;
                j--;
            }

            // can't replace empty substring
            if (curr == 0)
                return false;
            
            // leading with 0, bad abbr
            if (val == 0)
                return false;
            curr--;
        }

        return curr == 0 && j == -1;
    }
};