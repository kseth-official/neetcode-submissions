class Solution {
public:
    bool validWordSquare(vector<string>& words) {
        int rows = words.size();

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < words[i].size(); ++j) {
                // The j-th row must exist.
                if (j >= rows) {
                    return false;
                }

                // The i-th character of the j-th row must exist.
                if (i >= words[j].size()) {
                    return false;
                }

                // Compare words[i][j] with words[j][i].
                if (words[i][j] != words[j][i]) {
                    return false;
                }
            }
        }

        return true;
    }
};
